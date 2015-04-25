/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /cache.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

stackable<Renderbuffer*> Cache::m_renderbuffers;
labler<Scene*> Cache::m_scenes;
stackable<Camera*> Cache::m_cameras;

//====================================
// CLEAR
//====================================

void Cache::clear() {
	clearScene();
	clearGlobal();
	debug::ok << "(Cache::clear) complete" << debug::flush;
}

void Cache::clearGlobal() {
	debug::note << "(Cache::clearGlobal) deleting Scenes ..." << debug::flush;
	m_scenes.clear();
	debug::note << "(Cache::clearGlobal) deleting Renderbuffers ..." << debug::flush;
	m_renderbuffers.clear();
}

void Cache::clearScene() {
	debug::note << "(Cache::clearScene) deleting Cameras ..." << debug::flush;
	m_cameras.clear();
}

//====================================
// GLOBAL
//====================================

stackable<Renderbuffer*>* Cache::renderbuffers() { return &m_renderbuffers; }
Renderbuffer* Cache::renderbuffer() { return m_renderbuffers.top(); }

labler<Scene*>* Cache::scenes() { return &m_scenes; }
Scene* Cache::scene() { return m_scenes.active(); }

//====================================
// SCENE
//====================================

stackable<Camera*>* Cache::cameras() { return &m_cameras; }
Camera* Cache::camera() { return m_cameras.top(); }

}
