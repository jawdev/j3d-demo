/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /timer.h
******************************************************************************/
#ifndef J3D_TIMER_H_
#define J3D_TIMER_H_
namespace j3d {

struct Timer {

	Timer() {
		last_time = chrono::high_resolution_clock::now();
		delta = 0;
	}

	float timeSinceEpoch() {
		chrono::high_resolution_clock::time_point t = chrono::high_resolution_clock::now();
		return float( chrono::duration_cast< chrono::duration< float > >( t.time_since_epoch() ).count() );
	}

	float calculateDelta() {
		chrono::high_resolution_clock::time_point t = chrono::high_resolution_clock::now();
		delta = float( chrono::duration_cast< chrono::duration< float > >( t-last_time ).count() );
		last_time = t;
		return delta;
	}

	chrono::high_resolution_clock::time_point last_time;
	float delta;

};

}
#endif
