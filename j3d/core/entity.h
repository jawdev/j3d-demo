/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/entity.h
*******************************************************************************/
#ifndef __J3D_CORE_ENTITY_H__
#define __J3D_CORE_ENTITY_H__
namespace j3d { namespace core {

/*******************************************************************************
* ENTITY
*******************************************************************************/

class Entity {
public:
	Entity();
	virtual ~Entity();

	void spatialize();
	virtual void update();
	virtual const mat4 &transform(bool invert = false);

	Entity *move(const vec3 &);
	Entity *rotate(const vec3 &);
	Entity *lookAt(const vec3 &);
	
	Entity *lock(bool);
	Entity *pos(const vec3 &);
	Entity *rot(const vec3 &);
	Entity *vel(const vec3 &);
	Entity *rvel(const vec3 &);
	Entity *collider(Collider *);

	bool locked() const;
	const vec3 &pos() const;
	const vec3 &rot() const;
	const vec3 &vel() const;
	const vec3 &rvel() const;
	Collider* collider() const;
	bool collidable() const;

protected:
	bool o_locked;
	bool o_calcd_transform;

	vec3 o_pos;
	vec3 o_rot;
	vec3 o_vel;
	vec3 o_rvel;

	mat4 o_mat_pos;
	mat4 o_mat_rot;
	mat4 o_mat_transform;

	Collider *op_collider;

};

} }
#endif
