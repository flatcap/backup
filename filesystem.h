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
	static FPtr create (void);
	Filesystem (Filesystem&& f);
	virtual ~Filesystem() = default;

	Filesystem& operator= (const Filesystem& f);
	Filesystem& operator= (Filesystem&& f);

	void swap (Filesystem& f);
	friend void swap (Filesystem& lhs, Filesystem& rhs);

	virtual bool accept (Visitor& v);

	std::string get_label (void) const;
	std::string set_label (const std::string& value);

protected:
	Filesystem (void) = default;
	Filesystem (const Filesystem& f);

	virtual Filesystem* clone (void);

private:
	std::string label;
};


#endif // _FILESYSTEM_H_

