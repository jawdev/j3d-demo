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
// UPDATE
//====================================

void Entity::simulate( float dtime ) {
	m_position += m_velocity*dtime;
	m_rotation += m_spin*dtime;
}

//====================================
// ATTRIBUTES
//====================================

Entity* Entity::position( vec3 v ) { m_position = v; return this; }
Entity* Entity::rotation( vec3 v ) { m_rotation = v; return this; }
Entity* Entity::velocity( vec3 v ) { m_velocity = v; return this; }
Entity* Entity::spin( vec3 v ) { m_spin = v; return this; }

Entity* Entity::look( vec3 v ) {
	float dx = m_position.x-v.x;
	float dz = m_position.z-v.z;
	m_rotation.y = atan2( dx, dz );
	float hyp = sqrt( dx*dx+dz*dz );
	m_rotation.x = ( hyp == 0 ? 0 : -atan( ( m_position.y-v.y )/hyp ) );
	return this;
}

vec3 Entity::position() { return m_position; }
vec3 Entity::rotation() { return m_rotation; }
vec3 Entity::velocity() { return m_velocity; }
vec3 Entity::spin() { return m_spin; }

mat4 Entity::transform() {
	vmath::translation( &m_mat_translation, m_position );
	vmath::rotation( &m_mat_rotation, m_rotation );
	m_mat_transform = m_mat_translation*m_mat_rotation;
	return m_mat_transform;
}


}
