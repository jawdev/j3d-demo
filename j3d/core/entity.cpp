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
	o_attached = false;
	op_attachment = nullptr;
}

Entity::~Entity() {}

////////////////////////////////////////
// MAIN

void Entity::spatialize(bool force_delta)
{
	if (o_locked)
		return;
	if (o_attached && !force_delta) {
		o_pos = op_attachment->pos() + o_attachment_offsets[0];
		o_rot = op_attachment->rot() + o_attachment_offsets[1];
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
Entity *Entity::collider(Collider *c) { op_collider = c; return this; }
Entity *Entity::attach(Entity *e, const vec3 &p, const vec3 &r)
{
	op_attachment = e;
	o_attachment_offsets[0] = p;
	o_attachment_offsets[1] = r;
	return this;
}

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

bool Entity::attached() const { return o_attached; }
Entity *Entity::attachment() const { return op_attachment; }

} }
