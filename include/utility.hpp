// This file is part of libZelda.
//
// libZelda is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libZelda is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libZelda.  If not, see <http://www.gnu.org/licenses/>

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>
#include "Types.hpp"

namespace zelda
{
namespace utility
{

bool isEmpty(Int8*, Uint32);

Uint16 swapU16(Uint16 val );
Int16 swap16 (Int16 val );
Uint32   swapU32(Uint32 val);
Int32   swap32 (Int32 val );
Uint64 swapU64(Uint64 val);
Int64  swap64 (Int64 val);

float swapFloat(float val);
double  swapDouble(double val);

bool isSystemBigEndian();

void fillRandom(Uint8 * rndArea, Uint8 count);

} // utility
} // zelda

#endif
