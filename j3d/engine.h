/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /engine.h
******************************************************************************/
#ifndef J3D_ENGINE_H_
#define J3D_ENGINE_H_
namespace j3d {

class Engine {
public:

	static bool init_complete;
	static int argc;
	static char** argv;
	static Display* display;
	static Timer* timer;
	static Scene* scene;

public:

	//====================================
	// MAIN
	//====================================

	static void init( int _argc, char** _argv );
	static void quit( int exit_code = -1 );
	static void run();
	static void cycle();

	//====================================
	// SCENE
	//====================================

	static Scene* addScene( char* name, Scene* s, bool load = false );
	static Scene* loadScene( char* name );
	static void unloadScene();

	static Mesh* loadMesh( char* name, Mesh* m );

};

}
#endif
