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

void Entity::spatialize(bool force_delta)
{
	if (o_locked)
		return;
	if (o_attached && !force_delta) {
		syncAttachment();
		return;
	}
	o_pos += o_vel * util::cycle::delta();
	o_rot += o_rvel * util::cycle::delta();
}

void Entity::update()
{
	spatialize();
}

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

////////////////////////////////////////
// SUPPLEMENTS

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

Entity *Entity::vel(const vec3 &v) { o_vel = v; return this; }
Entity *Entity::rvel(const vec3 &v) { o_rvel = v; return this; }

const vec3 &Entity::vel() const { return o_vel; }
const vec3 &Entity::rvel() const { return o_rvel; }

} }
