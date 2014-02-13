/* Copyright (c) 2014 Richard Russon (FlatCap)
 *
 * This file is part of DParted.
 *
 * DParted is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DParted is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DParted.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "container.h"

/**
 * Container (default)
 */
Container::Container (void) :
	size(0)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
}

/**
 * Container (copy)
 */
Container::Container (const Container &c) :
	Backup (c),
	name (c.name),
	size (c.size)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	for (auto child : c.children) {
		children.push_back (child->backup());
	}
}

/**
 * ~Container
 */
Container::~Container()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
}


/**
 * operator=
 */
Container &
Container::operator= (const Container &c)
{
	Backup::operator= (c);

	name     = c.name;
	size     = c.size;
	children = c.children;

	return *this;
}


/**
 * new
 */
void *
Container::operator new (size_t size)
{
	Container *c = (Container*) ::operator new (size);

#if 0
	std::cout << "new object " << c << std::endl;
#endif

	return c;
}

/**
 * delete
 */
void
Container::operator delete (void *ptr)
{
	if (!ptr)
		return;

#if 0
	Container *c = (Container *) (ptr);
	std::cout << "delete object " << c << std::endl;
#endif

	::operator delete (ptr);
}


/**
 * create (static)
 */
CPtr
Container::create (void)
{
	CPtr c (new Container);

	return c;
}


/**
 * backup
 */
CPtr
Container::backup (void)
{
	//Backup::backup();
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	CPtr old (new Container (*this));
	return old;
}

/**
 * restore
 */
void
Container::restore (void)
{
	Backup::restore();
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	changed();
	for (auto c : children) {
		c->restore();
	}
}


/**
 * get_size
 */
int
Container::get_size (void)
{
	return size;
}

/**
 * set_size
 */
int
Container::set_size (int value)
{
	int old = size;
	size = value;
	changed();
	return old;
}

/**
 * add_child
 */
int
Container::add_child (CPtr child)
{
	children.push_back (child);
	changed();
	return children.size();
}

/**
 * remove_child
 */
void
Container::remove_child (size_t index)
{
	if (index >= children.size())
		return;

	children.erase (children.begin()+index);
	changed();
}

/**
 * get_children
 */
const std::vector<CPtr>&
Container::get_children (void)
{
	return children;
}
