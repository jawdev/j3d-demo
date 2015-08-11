/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/debug.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d { namespace util {

int debug_settings::level = J3D_DEBUG_LEVEL_WARN;
bool debug_settings::colorize = true;

void debug(int l, bool c)
{
	debug_settings::level = l;
	debug_settings::colorize = c;
}

} }
