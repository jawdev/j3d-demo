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
Scene* Engine::scene = nullptr;

//====================================
// MAIN
//====================================

void Engine::init( int _argc, char** _argv ) {
	if( init_complete ) {
		debug::warn << "(Engine::init) Engine has already been initialized" << debug::flush;
		return;
	}
	argc = _argc;
	argv = _argv;
	debug::note << "(Engine::init) creating Display ..." << debug::flush;
	display = new Display();
	debug::note << "(Engine::init) creating Timer ..." << debug::flush;
	timer = new Timer();
	debug::ok << "(Engine::init) complete" << debug::flush;
	init_complete = true;
}

void Engine::quit( int exit_code ) {
	if( init_complete ) {
		debug::note << "(Engine::quit) deleting Timer ..." << debug::flush;
		SAFE_DELETE( timer );
		debug::note << "(Engine::quit) deleting Display ..." << debug::flush;
		SAFE_DELETE( display );
		debug::note << "(Engine::quit) clearing Cache ..." << debug::flush;
		Cache::clear();
		argc = 0;
		argv = nullptr;
		init_complete = false;
		debug::ok << "(Engine::quit) complete" << debug::flush;
	} else debug::warn << "(Engine::quit) Engine has not been initialized" << debug::flush;
	if( exit_code >= 0 ) exit( exit_code );
}

void Engine::run() {
	if( scene == nullptr ) debug::fatal << "(Engine::run) no Scene" << debug::flush;
	display->mainLoop();
}

void Engine::cycle() {
	timer->calculateDelta();
	scene->update( timer->delta );
}

//====================================
// SCENE
//====================================

Scene* Engine::addScene( char* name, Scene* s, bool load ) {
	Cache::scenes()->add( name, s, load );
	if( load ) {
		unloadScene();
		scene = s;
		scene->load();
	}
	return s;
}

Scene* Engine::loadScene( char* name ) {
	unloadScene();
	scene = Cache::scenes()->find( name, true );
	scene->load();
	return scene;
}

void Engine::unloadScene() {
	if( scene == nullptr ) return;
	scene->unload();
	scene = nullptr;
}

}
