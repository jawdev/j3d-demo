/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /cache.h
******************************************************************************/
#ifndef J3D_CACHE_H_
#define J3D_CACHE_H_
namespace j3d {

class Cache {
public:

	//====================================
	// CLEAR
	//====================================

	static void clear();
	static void clearGlobal();
	static void clearScene();

	//====================================
	// GLOBAL
	//====================================

	static stackable<Renderbuffer*>* renderbuffers();
	static Renderbuffer* renderbuffer();

	static labler<Scene*>* scenes();
	static Scene* scene();

	//====================================
	// SCENE
	//====================================

	static stackable<Camera*>* cameras();
	static Camera* camera();

private:

	static stackable<Renderbuffer*> m_renderbuffers;
	static labler<Scene*> m_scenes;

	static stackable<Camera*> m_cameras;

};

}
#endif
