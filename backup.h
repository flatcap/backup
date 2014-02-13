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

#ifndef _BACKUP_H_
#define _BACKUP_H_

#include "pointers.h"

/**
 * class Backup
 */
class Backup
{
public:
	Backup();
	Backup (const Backup &b);
	virtual ~Backup();

	Backup & operator= (const Backup &b);

	virtual CPtr backup (void);
	virtual void restore (void);

	int get_seqnum (void);

protected:
	void changed (void);

private:
	int seqnum;
};


#endif // _BACKUP_H_

