/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/cycle.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

cycle_triggers::cycle_triggers()
{
	reset();
}

float cycle::last_time = 0;
float cycle::new_time = 0;
float cycle::delta = 0;
cycle_triggers cycle::triggers;

void cycle::tick()
{
	new_time = now();
	delta = new_time - last_time;
}

void cycle::flush()
{
	last_time = new_time;
	triggers.reset();
}

} }
