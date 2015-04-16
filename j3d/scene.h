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

private:
};

}
#endif
