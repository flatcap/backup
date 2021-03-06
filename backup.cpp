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

#include "backup.h"

static int base_seqnum = 1000;

/**
 * Backup (default)
 */
Backup::Backup()
{
	seqnum = base_seqnum;
	std::cout << "Backup ctor (default): " << seqnum << std::endl;
	base_seqnum += 1000;
}

/**
 * Backup (copy)
 */
Backup::Backup (const Backup& b) :
	seqnum (b.seqnum)
{
	std::cout << "Backup ctor (copy): " << b.seqnum << std::endl;
}

/**
 * Backup (move)
 */
Backup::Backup (Backup&& b)
{
	std::cout << "Backup ctor (move): " << b.seqnum << std::endl;
	swap (b);
}


/**
 * operator=
 */
Backup&
Backup::operator= (const Backup& b)
{
	// DON'T copy seqnum
	// Nothing to do, for now

	return *this;
}


/**
 * swap (member)
 */
void
Backup::swap (Backup& b)
{
	std::cout << "Backup swap (member): " << seqnum << ", " << b.seqnum << std::endl;
	std::swap (seqnum, b.seqnum);
}

/**
 * swap (global)
 */
void swap (Backup& lhs, Backup& rhs)
{
	std::cout << "Backup swap (global): " << lhs.seqnum << ", " << rhs.seqnum << std::endl;
	lhs.swap (rhs);
}


/**
 * backup
 */
CPtr
Backup::backup (void)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	seqnum = (seqnum+100)/100*100;

	return nullptr;
}

/**
 * restore
 */
void
Backup::restore (void)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	seqnum = (seqnum+100)/100*100;
}


/**
 * get_seqnum
 */
int
Backup::get_seqnum (void)
{
	return seqnum;
}


/**
 * changed
 */
void
Backup::changed (void)
{
	if (seqnum < 1)
		return;

	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	seqnum++;
}

