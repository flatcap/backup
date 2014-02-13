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

#ifndef _PARTITION_H_
#define _PARTITION_H_

#include "container.h"

/**
 * class Partition
 */
class Partition : public Container
{
public:
	static PPtr create (void);
	Partition (Partition&& p);
	virtual ~Partition() = default;

	Partition& operator= (const Partition& p);
	Partition& operator= (Partition&& p);

	void swap (Partition& p);
	friend void swap (Partition& lhs, Partition& rhs);

	virtual bool accept (Visitor& v);

	int get_id (void) const;
	int set_id (int value);

protected:
	Partition (void) = default;
	Partition (const Partition& p);

	virtual Partition* clone (void);

private:
	int id = 0;
};


#endif // _PARTITION_H_

