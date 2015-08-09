/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/collider.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* COLLIDER
*******************************************************************************/

Collider::Collider(collider_shape_t shape)
{
	m_shape = shape;
	m_collidable = (m_shape != collider_shape_t::NONE);
}

Collider::~Collider() {}

////////////////////////////////////////
// COLLIDE FILTER

Collision Collider::collide(Collider *other, vec3 *v1, vec3 *v2)
{
	if (!m_collidable)
		return collision_none;
	else if (!other->collidable())
		return collision_none;
	switch (m_shape) {
	case collider_shape_t::BOX:
		switch (other->shape()) {
		case collider_shape_t::BOX:
			return boxBox(other, v1, v2);
		case collider_shape_t::SPHERE:
			return boxSphere(other, v1, v2);
		case collider_shape_t::ELLIPSOID:
			return boxEllipsoid(other, v1, v2);
		default:
			return collision_none;
		}
	case collider_shape_t::SPHERE:
		switch (other->shape()) {
		case collider_shape_t::BOX:
			return other->boxSphere(this, v2, v1).invert();
		case collider_shape_t::SPHERE:
			return sphereSphere(other, v1, v2);
		case collider_shape_t::ELLIPSOID:
			return sphereEllipsoid(other, v1, v2);
		default:
			return collision_none;
		}
	case collider_shape_t::ELLIPSOID:
		switch (other->shape()) {
		case collider_shape_t::BOX:
			return other->boxEllipsoid(this, v2, v1).invert();
		case collider_shape_t::SPHERE:
			return other->sphereEllipsoid(this, v2, v1).invert();
		case collider_shape_t::ELLIPSOID:
			return ellipsoidEllipsoid(other, v1, v2);
		default:
			return collision_none;
		}
	default:
		return collision_none;
	}
}

////////////////////////////////////////
// COLLIDE BOX

Collision Collider::boxBox(Collider *other, vec3 *v1, vec3 *v2)
{
	if (v1->x + m_min.x > v2->x + other->max().x)
		return collision_none;
	if (v1->x + m_max.x < v2->x + other->min().x)
		return collision_none;
	if (v1->y + m_min.y > v2->y + other->max().y)
		return collision_none;
	if (v1->y + m_max.y < v2->y + other->min().y)
		return collision_none;
	if (v1->z + m_min.z > v2->z + other->max().z)
		return collision_none;
	if (v1->z + m_max.z < v2->z + other->min().z)
		return collision_none;
	return {
		true
	};
}

Collision Collider::boxSphere(Collider *other, vec3 *v1, vec3 *v2)
{
	return collision_none;
}

Collision Collider::boxEllipsoid(Collider *other, vec3 *v1, vec3 *v2)
{
	return collision_none;
}

////////////////////////////////////////
// COLLIDE SPHERE

Collision Collider::sphereSphere(Collider *other, vec3 *v1, vec3 *v2)
{
	return collision_none;
}

Collision Collider::sphereEllipsoid(Collider *other, vec3 *v1, vec3 *v2)
{
	return collision_none;
}

////////////////////////////////////////
// COLLIDE ELLIPSOID

Collision Collider::ellipsoidEllipsoid(Collider *other, vec3 *v1, vec3 *v2)
{
	return collision_none;
}

////////////////////////////////////////
// GET

collider_shape_t Collider::shape() { return m_shape; }
const vec3 &Collider::min() { return m_min; }
const vec3 &Collider::max() { return m_max; }
bool Collider::collidable() { return m_collidable; }

}
