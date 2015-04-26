/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /scene.h
******************************************************************************/
#ifndef J3D_SCENE_H_
#define J3D_SCENE_H_
namespace j3d {

class Scene {
public:

	Scene() {}
	virtual ~Scene() { unload(); }

	virtual void load() {}
	virtual void unload() {}
	virtual void update( float dtime ) {}

	virtual void onKeyDown( unsigned char key ) {}
	virtual void onKeyDown( unsigned char key, int x, int y ) { onKeyDown( key ); }
	virtual void onKeyUp( unsigned char key ) {}
	virtual void onKeyUp( unsigned char key, int x, int y ) { onKeyUp( key ); }
	virtual void onSpecialDown( int key ) {}
	virtual void onSpecialDown( int key, int x, int y ) { onSpecialDown( key ); }
	virtual void onSpecialUp( int key ) {}
	virtual void onSpecialUp( int key, int x, int y ) { onSpecialUp( key ); }

	virtual void onMouseDown( int button, int x, int y ) {}
	virtual void onMouseUp( int button, int x, int y ) {}
	virtual void onMouseMove( int new_x, int new_y, int old_x, int old_y ) {}

private:
};

}
#endif
