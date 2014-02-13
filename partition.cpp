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

/**
 * Partition (default)
 */
Partition::Partition (void) :
	id(0)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	name = "partition";
}

/**
 * Partition (copy)
 */
Partition::Partition (const Partition &p) :
	Container (p),
	id (p.id)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
}

/**
 * ~Partition
 */
Partition::~Partition()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
}


/**
 * operator=
 */
Partition &
Partition::operator= (const Partition &p)
{
	Container::operator= (p);

	id = p.id;

	return *this;
}


/**
 * create (static)
 */
PPtr
Partition::create (void)
{
	PPtr p (new Partition);

	return p;
}


/**
 * backup
 */
CPtr
Partition::backup (void)
{
	//Container::backup();
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	CPtr old (new Partition (*this));
	return old;
}

/**
 * restore
 */
void
Partition::restore (void)
{
	Container::restore();
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
}


/**
 * get_id
 */
int
Partition::get_id (void)
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


