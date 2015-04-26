/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /object.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

///////////////////////////////////////////////// Object

Object::Object( char* mesh_name, vec4 color ) {
	mp_mesh = Cache::meshes()->find( mesh_name );
	m_color = color;
}

Object::~Object() {}

//=====================================
// UPDATE
//=====================================

void Object::update( float dtime ) {
	simulate( dtime );
}

void Object::render() {
	mp_mesh->render();
}

//=====================================
// ATTRIBUTES
//=====================================

Object* Object::color( vec4 v ) { m_color = v; return this; }

vec4 Object::color() { return m_color; }

}
