/* Copyright (c) 2013 Richard Russon (FlatCap)
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307, USA.
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
	Backup (Backup&& b);
	virtual ~Backup() = default;

	Backup& operator= (const Backup& b);
	Backup& operator= (Backup&& b);

	void swap (Backup& b);
	friend void swap (Backup& lhs, Backup& rhs);

	virtual CPtr backup (void);
	virtual void restore (void);

	int get_seqnum (void);

protected:
	Backup (void);
	Backup (const Backup& b);

	void changed (void);

private:
	int seqnum = 1;
};


#endif // _BACKUP_H_

