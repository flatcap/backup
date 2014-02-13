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

#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <vector>

#include "pointers.h"
#include "backup.h"

/**
 * class Container
 */
class Container : public Backup
{
public:
	Container (void);
	Container (const Container &c);
	virtual ~Container();

	Container & operator= (const Container &c);

	void * operator new (size_t size);
	void operator delete (void *ptr);

	static CPtr create (void);

	virtual CPtr backup (void);
	virtual void restore (void);

	int get_size (void);
	int set_size (int value);
	int add_child (CPtr child);
	void remove_child (size_t index);
	const std::vector<CPtr>& get_children (void);

	std::string name;
private:
	int size;
	std::vector<CPtr> children;
};


#endif // _CONTAINER_H_

