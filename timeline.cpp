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
#include <sstream>

#include "timeline.h"
#include "container.h"
#include "dot.h"
#include "utils.h"

/**
 * Timeline
 */
Timeline::Timeline (void)
{
}

/**
 * ~Timeline
 */
Timeline::~Timeline()
{
}


/**
 * push
 */
void
Timeline::push (const Action &action)
{
	timeline.push_back (action);
}

/**
 * pop
 */
Action
Timeline::pop (void)
{
	Action a = timeline.back();
	timeline.pop_back();
	return a;
}


/**
 * backup
 */
CPtr
Timeline::backup (const CPtr &root, const std::string &desc)
{
	CPtr copy = root->backup();

	push (Action(root, copy, desc));

	return copy;
}

/**
 * restore
 */
void
Timeline::restore (void)
{
	CPtr        current;
	CPtr        old;
	std::string desc;

	std::tie (current, old, desc) = pop();

	*current = *old;	// copy the objects, not the smart pointers

	current->restore();
}


/**
 * dump
 */
void
Timeline::dump (void)
{
	std::cout << "Timeline:\n";
	for (auto a : timeline) {
		CPtr        current;
		CPtr        old;
		std::string desc;

		std::tie (current, old, desc) = a;

		std::cout << '\t' << current << ", " << old << ", " << desc << std::endl;
	}
	std::cout << std::endl;
}

/**
 * display
 */
void
Timeline::display (void)
{
	if (timeline.size() == 0)
		return;

	std::stringstream dot;
	std::string desc;
	int count = 1;

	dot << "digraph disks {\n";
	dot << "graph [ rankdir=\"TB\", color=\"white\",bgcolor=\"#000000\" ];\n";
	dot << "node [ shape=\"record\", color=\"black\", fillcolor=\"lightcyan\", style=\"filled\" ];\n";
	dot << "edge [ penwidth=3.0,color=\"#cccccc\" ];\n";
	dot << "\n";

	for (auto t : timeline) {
		CPtr c;

		std::tie (std::ignore, c, desc) = t;

		if (!c) {
			std::cout << "empty ptr\n";
			continue;
		}

		dot << "subgraph cluster_" << count++ << " { color=red;\n";
		dot << "fontcolor = \"white\";\n";
		dot << "label = \"" + desc + "\";\n";
		dot << dump_dot_small (c);
		dot << "}\n";
	}

	dot << "\n}";
	dot << "\n";

	std::string input = dot.str();
	//std::cout << input << std::endl;

	int offset = 0;
	int screen_x = -1-(offset*400);

	std::string command = "dot -Tpng | display -title \"timeline:" + std::to_string(count-1) + "\" -gravity NorthEast -geometry " + std::to_string(screen_x) + "+0 -resize 80% - &";

	execute_command (command, input);
}


