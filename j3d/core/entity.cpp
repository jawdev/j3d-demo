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

Entity::Entity()
{
	o_locked = false;
	o_calcd_transform = false;
	op_collider = nullptr;
}

Entity::~Entity() {}

////////////////////////////////////////
// MAIN

void Entity::spatialize()
{
	if (o_locked)
		return;
	o_pos += o_vel * cycle::delta;
	o_rot += o_rvel * cycle::delta;
}

void Entity::update()
{
	spatialize();
}

const mat4 &Entity::transform(bool invert)
{
	if (o_locked && o_calcd_transform)
		return o_mat_transform;
	vmath::translation(&o_mat_pos, o_pos);
	vmath::rotation(&o_mat_rot, o_rot);
	if (invert)
		o_mat_transform = o_mat_pos * o_mat_rot;
	else
		o_mat_transform = o_mat_rot * o_mat_pos;
	o_calcd_transform = true;
	return o_mat_transform;
}

////////////////////////////////////////
// SUPPLEMENTS

Entity *Entity::move(const vec3 &v) { o_pos += v; return this; }
Entity *Entity::rotate(const vec3 &v) { o_rot += v; return this; }

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

Entity *Entity::pos(const vec3 &v) { o_pos = v; return this; }
Entity *Entity::rot(const vec3 &v) { o_rot = v; return this; }
Entity *Entity::vel(const vec3 &v) { o_vel = v; return this; }
Entity *Entity::rvel(const vec3 &v) { o_rvel = v; return this; }

bool Entity::locked() const { return o_locked; }
const vec3 &Entity::pos() const { return o_pos; }
const vec3 &Entity::rot() const { return o_rot; }
const vec3 &Entity::vel() const { return o_vel; }
const vec3 &Entity::rvel() const { return o_rvel; }
Collider *Entity::collider() const { return op_collider; }

bool Entity::collidable() const
{
	if (op_collider == nullptr)
		return false;
	return op_collider->collidable();
}

} }
