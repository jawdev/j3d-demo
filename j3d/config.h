/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/config.h
*******************************************************************************/
#ifndef __J3D_CONFIG_H__
#define __J3D_CONFIG_H__
namespace j3d {

/*******************************************************************************
* SETUP
*******************************************************************************/

struct Config {

	int argc;
	char **argv;
	
	int window_width;
	int window_height;
	int window_start_x;
	int window_start_y;
	string window_title;

	float mouse_buffer_time;
	float render_distance_near;
	float render_distance_far;

	bool register_atexit;
	bool register_sigint;

	Config() { reset(); }
	void reset()
	{
		argc = 0;
		argv = nullptr;
		window_width = 800;
		window_height = 600;
		window_start_x = 1000;
		window_start_y = 100;
		mouse_buffer_time = 0.01f;
		render_distance_near = 1;
		render_distance_far = 1000;
		register_atexit = true;
		register_sigint = true;
	}
};

}
#endif
