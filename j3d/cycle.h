/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/cycle.h
*******************************************************************************/
#ifndef __J3D_CYCLE_H__
#define __J3D_CYCLE_H__
namespace j3d {

struct cycle_triggers {
	bool reshape;

	cycle_triggers();
	void reset()
	{
		reshape = false;
	}
};

struct cycle {
	static double last_time;
	static double new_time;
	static float delta;
	static cycle_triggers triggers;

	static void tick();
	static void flush();
};

}
#endif
