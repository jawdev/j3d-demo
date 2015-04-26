/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /main.cc
******************************************************************************/

#include "inc.h"

int main( int argc, char* argv[] ) {

	// SETUP

	j3d::Settings::glut_cursor = GLUT_CURSOR_LEFT_ARROW;
	j3d::Engine::init( argc, argv );

	// GO

	j3d::Engine::addScene( "test", new SceneTest(), true );
	j3d::Engine::run();

	return 0;
}
