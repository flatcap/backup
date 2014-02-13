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

#ifndef _TIMELINE_H_
#define _TIMELINE_H_

#include <tuple>
#include <deque>
#include <string>

#include "pointers.h"

typedef std::tuple<CPtr, CPtr, std::string> Action;	// Current, Old, Description

/**
 * class Timeline
 */
class Timeline
{
public:
	Timeline (void);
	virtual ~Timeline();

	void push (const Action& action);
	Action pop (void);

#if 0
	CPtr backup (const CPtr& root, const std::string& desc);
	void restore (void);
#endif
	void backup (CPtr& orig, CPtr& work, const std::string& desc);

	void dump (void);
	void display (void);

protected:
	std::deque<Action> timeline;
};


#endif // _TIMELINE_H_

