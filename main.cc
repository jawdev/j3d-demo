/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /main.cc
******************************************************************************/

#include "j3d/j3d.h"

int main( int argc, char* argv[] ) {
	j3d::Engine::init( argc, argv );
	j3d::Engine::run();
	j3d::Engine::quit();
	return 0;
}
