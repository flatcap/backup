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

#ifndef _POINTERS_H_
#define _POINTERS_H_

#include <memory>

class Timeline;
class Container;
class Disk;
class Partition;
class Filesystem;

typedef std::shared_ptr<Timeline>   TPtr;
typedef std::shared_ptr<Container>  CPtr;
typedef std::shared_ptr<Disk>       DPtr;
typedef std::shared_ptr<Partition>  PPtr;
typedef std::shared_ptr<Filesystem> FPtr;

#endif // _POINTERS_H_

