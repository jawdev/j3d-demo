/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/collider.h
*******************************************************************************/
#ifndef __J3D_COLLIDER_H__
#define __J3D_COLLIDER_H__
namespace j3d {

/*******************************************************************************
* COLLISION
*******************************************************************************/

struct Collision {
	bool happened;
	Collision invert()
	{
		return *this;
	}
};

const Collision collision_none = {
	false
};

/*******************************************************************************
* COLLIDER
*******************************************************************************/

enum class collider_shape_t {
	BOX,
	SPHERE,
	ELLIPSOID,
	CUSTOM,
	NONE
};

class Collider {
public:
	Collider(collider_shape_t = collider_shape_t::BOX);
	virtual ~Collider();

	virtual Collision collide(Collider *, vec3 *, vec3 *);

private:
	virtual Collision boxBox(Collider *, vec3 *, vec3 *);
	virtual Collision boxSphere(Collider *, vec3 *, vec3 *);
	virtual Collision boxEllipsoid(Collider *, vec3 *, vec3 *);

	virtual Collision sphereSphere(Collider *, vec3 *, vec3 *);
	virtual Collision sphereEllipsoid(Collider *, vec3 *, vec3 *);

	virtual Collision ellipsoidEllipsoid(Collider *, vec3 *, vec3 *);

public:
	virtual collider_shape_t shape();
	virtual const vec3 &min();
	virtual const vec3 &max();
	virtual bool collidable();

private:
	collider_shape_t m_shape;
	bool m_collidable;
	vec3 m_min;
	vec3 m_max;
};

}
#endif
