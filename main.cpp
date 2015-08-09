#include "j3d/j3d.h"
using namespace j3d;

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
	
	engine::quit();
	return 0;
}
