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

#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_

#include "container.h"

/**
 * class Filesystem
 */
class Filesystem : public Container
{
public:
	Filesystem (void);
	Filesystem (const Filesystem &f);
	virtual ~Filesystem();

	Filesystem & operator= (const Filesystem &f);

	static FPtr create (void);

	virtual CPtr backup (void);
	virtual void restore (void);

	std::string get_label (void);
	std::string set_label (const std::string &value);

private:
	std::string label;
};


#endif // _FILESYSTEM_H_

