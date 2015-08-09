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
	string window_title;

	float mouse_buffer_time;

	bool register_atexit;
	bool register_sigint;

	Config() { reset(); }
	void reset()
	{
		argc = 0;
		argv = nullptr;
		window_width = 800;
		window_height = 600;
		mouse_buffer_time = 0.01f;
		register_atexit = true;
		register_sigint = true;
	}
};

}
#endif
