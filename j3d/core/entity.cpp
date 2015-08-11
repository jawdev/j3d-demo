/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/entity.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* ENTITY
*******************************************************************************/

Entity::Entity(bool locked) : EntityBase<vec3>(locked)
{
	o_calcd_transform = false;
}

Entity::~Entity() {}

////////////////////////////////////////
// MAIN

const mat4 &Entity::transform()
{
	if (o_locked && o_calcd_transform)
		return o_mat_transform;
	vmath::translation(&o_mat_pos, o_pos);
	vmath::rotation(&o_mat_rot, o_rot);
	o_mat_transform = o_mat_pos * o_mat_rot;
	o_calcd_transform = true;
	return o_mat_transform;
}

Entity *Entity::lookAt(const vec3 &v)
{
	float dx = o_pos.x - v.x;
	float dz = v.z - o_pos.z;
	o_rot.y = atan2(dz, dx);
	float h = sqrt(dx * dx + dz * dz);
	o_rot.x = ( h == 0 ? 0 : atan((v.y - o_pos.y) / h));
	return this;
}

////////////////////////////////////////
// GET SET

Entity *Entity::lock(bool b)
{
	o_locked = b; 
	o_calcd_transform = false;
	return this;
}

} }
