/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* main.cpp
*******************************************************************************/

/*
 * 0. include j3d.h
 */
#include "demo/inc.h"


int main(int argc, char *argv[])
{
	/*
	 * 1. set debug level
	 */
	util::debug(J3D_DEBUG_LEVEL_ALL, true);
	
	/*
	 * 2. set config
	 * 3. init engine
	 */
	Config config;
		config.argc = argc;
		config.argv = argv;
		config.window_width = 800;
		config.window_height = 600;
		config.window_title = "J3D Demo";
	engine::init(config);


	/*
	 * 4. create scenes
	 */
	new Demo();
	
	/*
	 * 5. go!
	 */
	engine::run();

	return 0;
}
