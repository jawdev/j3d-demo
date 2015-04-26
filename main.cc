/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /main.cc
******************************************************************************/

#include "j3d/j3d.h"
#include "scenes/scenes.h"

int main( int argc, char* argv[] ) {

	j3d::Settings::glut_cursor = GLUT_CURSOR_LEFT_ARROW;
	j3d::Engine::init( argc, argv );

	j3d::Engine::addScene( "a", new SceneA(), true );

	j3d::Engine::run();

	return 0;
}
