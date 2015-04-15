/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /engine.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

bool Engine::init_complete = false;
int Engine::argc = 0;
char** Engine::argv = nullptr;
Display* Engine::display = nullptr;
Timer* Engine::timer = nullptr;

//====================================
// MAIN
//====================================

void Engine::init( int _argc, char** _argv ) {
	if( init_complete ) {
		Debug::warn( "(Engine::init) Engine has already been initialized" );
		return;
	}
	argc = _argc;
	argv = _argv;
	display = new Display();
	timer = new Timer();
	Debug::ok( "(Engine::init) success" );
	init_complete = true;
}

void Engine::quit( int exit_code ) {
	if( init_complete ) {
		SAFE_DELETE( timer );
		SAFE_DELETE( display );
		argc = 0;
		argv = nullptr;
		init_complete = false;
		Debug::ok( "(Engine::quit) success" );
	} else Debug::warn( "(Engine::quit) Engine has not been initialized" );
	if( exit_code >= 0 ) exit( exit_code );
}

void Engine::run() {
	display->mainLoop();
}

void Engine::cycle() {
	timer->calculateDelta();
}

}
