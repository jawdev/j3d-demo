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
		Debug::warn( "(Engine::init) Engine has already been initialized" );
		return;
	}
	argc = _argc;
	argv = _argv;
	Debug::note( "(Engine::init) creating Display ..." );
	display = new Display();
	Debug::note( "(Engine::init) creating Timer ..." );
	timer = new Timer();
	Debug::ok( "(Engine::init) complete" );
	init_complete = true;
}

void Engine::quit( int exit_code ) {
	if( init_complete ) {
		Debug::note( "(Engine::quit) deleting Timer ..." );
		SAFE_DELETE( timer );
		Debug::note( "(Engine::quit) deleting Display ..." );
		SAFE_DELETE( display );
		Debug::note( "(Engine::quit) clearing Cache ..." );
		Cache::clear();
		argc = 0;
		argv = nullptr;
		init_complete = false;
		Debug::ok( "(Engine::quit) complete" );
	} else Debug::warn( "(Engine::quit) Engine has not been initialized" );
	if( exit_code >= 0 ) exit( exit_code );
}

void Engine::run() {
	if( scene == nullptr ) Debug::fatal( "(Engine::run) no Scene" );
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
	}
	return s;
}

Scene* Engine::loadScene( char* name ) {
	unloadScene();
	scene = Cache::scenes()->get( name );
	return scene;
}

void Engine::unloadScene() {
	if( scene == nullptr ) return;
	scene->unload();
	scene = nullptr;
}

}
