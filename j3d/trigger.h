/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /trigger.h
******************************************************************************/
#ifndef J3D_TRIGGER_H_
#define J3D_TRIGGER_H_
namespace j3d {

struct trigger {

	static bool reshape;
	
	static void flush() {
		reshape = false;
	}

};

}
#endif
