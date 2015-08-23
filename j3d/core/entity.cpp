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

Entity::Entity() : EntityBase<vec3>()
{
	o_calcd_transform = false;
}

Entity::Entity(string shader_id) :
		EntityBase<vec3>(shader_id)
{
	o_calcd_transform = false;
}

Entity::~Entity() {}

////////////////////////////////////////
// MAIN

void Entity::update()
{
	EntityBase<vec3>::update();
	transform();
}

mat4 &Entity::transform()
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
	float dx = v.x() - o_pos.x();
	float dz = v.z() - o_pos.z();
	o_rot[1] = atan2(-dz, dx);
	float h = sqrt(dx * dx + dz * dz);
	o_rot[0] = (h == 0 ? 0 : atan((v.y() - o_pos.y()) / h));
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

const mat4 &Entity::matPos() const { return o_mat_pos; }
const mat4 &Entity::matRot() const { return o_mat_rot; }

} }
