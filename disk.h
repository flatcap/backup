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

#ifndef _DISK_H_
#define _DISK_H_

#include "container.h"

/**
 * class Disk
 */
class Disk : public Container
{
public:
	static DPtr create (void);
	Disk (Disk&& d);
	virtual ~Disk() = default;

	Disk& operator= (const Disk& d);
	Disk& operator= (Disk&& d);

	void swap (Disk& d);
	friend void swap (Disk& lhs, Disk& rhs);

	virtual bool accept (Visitor& v);

	std::string get_device (void) const;
	std::string set_device (const std::string value);

protected:
	Disk (void) = default;
	Disk (const Disk& d);

	virtual Disk* clone (void);

private:
	std::string device;
};


#endif // _DISK_H_

