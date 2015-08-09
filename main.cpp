#include "j3d/j3d.h"
using namespace j3d;

int main(int argc, char *argv[])
{
	debug(J3D_DEBUG_LEVEL_ALL, true);
	
	Setup setup;
		setup.argc = argc;
		setup.argv = argv;
		setup.window_width = 800;
		setup.window_height = 600;
		setup.window_title = "TEST";
	engine::init(setup);
	
	engine::quit();
	return 0;
}
