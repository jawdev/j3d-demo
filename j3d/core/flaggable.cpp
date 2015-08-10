/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/flaggable.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* FLAGGABLE
*******************************************************************************/

Flaggable::Flaggable(uint64_t start_flags)
{
	o_flags = start_flags;
}

Flaggable::~Flaggable() {}

void Flaggable::flag(uint64_t f)
{
	o_flags |= f;
}

void Flaggable::unflag(uint64_t f)
{
	o_flags &= ~f;
}

void Flaggable::noflags()
{
	o_flags = 0x0;
}

bool Flaggable::flagged(uint64_t f)
{
	return (o_flags&f);
}

bool Flaggable::unflagged(uint64_t f)
{
	return !flagged(f);
}

uint64_t Flaggable::flags()
{
	return o_flags;
}

} }
