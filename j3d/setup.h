/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/setup.h
*******************************************************************************/
#ifndef __J3D_SETUP_H__
#define __J3D_SETUP_H__
namespace j3d {

/*******************************************************************************
* SETUP
*******************************************************************************/

struct Setup {

	int argc;
	char **argv;
	
	int window_width;
	int window_height;
	string window_title;

	bool register_atexit;
	bool register_sigint;

	Setup() { reset(); }
	void reset()
	{
		argc = 0;
		argv = nullptr;
		window_width = 800;
		window_height = 600;
		register_atexit = true;
		register_sigint = true;
	}
};

}
#endif
