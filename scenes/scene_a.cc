/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /scenes/scene_a.cc
******************************************************************************/
#include "scenes.h"

SceneA::SceneA() {

}

void SceneA::load() {

	m_velocity = j3d::vec3( 1, 1, 1 );
	
}

void SceneA::unload() {
}

void SceneA::update( float dtime ) {
	m_position += m_velocity*dtime;
	cout << m_position << endl;
}
