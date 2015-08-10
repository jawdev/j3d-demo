/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* main.cpp
*******************************************************************************/
#include "inc.h"

int main(int argc, char *argv[])
{
	debug(J3D_DEBUG_LEVEL_ALL, true);
	
	Config config;
		config.argc = argc;
		config.argv = argv;
		config.window_width = 800;
		config.window_height = 600;
		config.window_title = "TEST";
	engine::init(config);

	new Demo();
	
	engine::run();
	return 0;
}
