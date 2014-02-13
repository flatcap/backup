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

#include <cstdio>
#include <string>

/**
 * execute_command
 */
unsigned int
execute_command (const std::string &command, std::string &input)
{
	FILE *file = nullptr;
	int count = 0;

	file = popen (command.c_str(), "we");
	if (file == nullptr) {
		printf ("popen failed");
		return -1;
	}

	count = fprintf (file, "%s\n", input.c_str());

	if (pclose (file) == -1) {
		printf ("pclose failed");
		return -1;
	}

	return count;
}


