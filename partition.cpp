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

#include "partition.h"
#include "visitor.h"

/**
 * create (static)
 */
PPtr
Partition::create (void)
{
	Partition* p = new Partition();

	p->name = "partition";

	PPtr pp (p);

	p->me = pp;	// keep a weak pointer to myself

	return pp;
}


/**
 * Partition (copy)
 */
Partition::Partition (const Partition& p) :
	Container (p),
	id (p.id)
{
	std::cout << "Partition ctor (copy): " << p.id << std::endl;
}

/**
 * Partition (move)
 */
Partition::Partition (Partition&& p)
{
	std::cout << "Partition ctor (move): " << p.id << std::endl;

	swap (p);
}


/**
 * operator= (copy)
 */
Partition&
Partition::operator= (const Partition& p)
{
	std::cout << "Partition assign (copy): " << id << ", " << p.id << std::endl;
	Container::operator= (p);

	id = p.id;

	return *this;
}

/**
 * operator= (move)
 */
Partition&
Partition::operator= (Partition&& p)
{
	std::cout << "Partition assign (move): " << id << ", " << p.id << std::endl;
	swap (p);
	return *this;
}


/**
 * swap (member)
 */
void
Partition::swap (Partition& p)
{
	std::cout << "Partition swap (member): " << id << ", " << p.id << std::endl;
	Container::swap (p);
	std::swap (id, p.id);
}

/**
 * swap (global)
 */
void swap (Partition& lhs, Partition& rhs)
{
	std::cout << "Partition swap (global): " << lhs.id << ", " << rhs.id << std::endl;
	lhs.swap (rhs);
}


/**
 * accept
 */
bool
Partition::accept (Visitor& v)
{
	PPtr p = std::dynamic_pointer_cast<Partition> (me.lock());
	if (!v.visit (p))
		return false;
	return visit_children (v);
}

/**
 * clone
 */
Partition*
Partition::clone (void)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	return new Partition (*this);
}


/**
 * get_id
 */
int
Partition::get_id (void) const
{
	return id;
}

/**
 * set_id
 */
int
Partition::set_id (int value)
{
	int old = id;
	id = value;
	changed();
	return old;
}


