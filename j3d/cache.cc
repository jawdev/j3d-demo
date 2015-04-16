/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /cache.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

stackable<Renderbuffer*> Cache::m_renderbuffers;
switchable<Scene*> Cache::m_scenes;
stackable<Camera*> Cache::m_cameras;

//====================================
// CLEAR
//====================================

void Cache::clear() {
	clearScene();
	clearGlobal();
	Debug::ok( "(Cache::clear) complete" );
}

void Cache::clearGlobal() {
	Debug::note( "(Cache::clearGlobal) deleting Scenes ..." );
	m_scenes.clear();
	Debug::note( "(Cache::clearGlobal) deleting Renderbuffers ..." );
	m_renderbuffers.clear();
}

void Cache::clearScene() {
	Debug::note( "(Cache::clearScene) deleting Cameras ..." );
	m_cameras.clear();
}

//====================================
// GLOBAL
//====================================

stackable<Renderbuffer*>* Cache::renderbuffers() { return &m_renderbuffers; }
Renderbuffer* Cache::renderbuffer() { return m_renderbuffers.top(); }

switchable<Scene*>* Cache::scenes() { return &m_scenes; }
Scene* Cache::scene() { return m_scenes.active(); }

//====================================
// SCENE
//====================================

stackable<Camera*>* Cache::cameras() { return &m_cameras; }
Camera* Cache::camera() { return m_cameras.top(); }

}
