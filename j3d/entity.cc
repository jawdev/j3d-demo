/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /entity.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

//====================================
// INIT
//====================================

Entity::Entity() {}

Entity::~Entity() {}


//====================================
// ATTRIBUTES
//====================================

Entity* Entity::position( vec3 v ) { m_position = v; return this; }
Entity* Entity::rotation( vec3 v ) { m_rotation = v; return this; }
Entity* Entity::velocity( vec3 v ) { m_velocity = v; return this; }
Entity* Entity::spin( vec3 v ) { m_spin = v; return this; }

vec3 Entity::position() { return m_position; }
vec3 Entity::rotation() { return m_rotation; }
vec3 Entity::velocity() { return m_velocity; }
vec3 Entity::spin() { return m_spin; }

}
