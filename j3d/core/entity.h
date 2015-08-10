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

	virtual void spatialize(bool force_delta = false);
	virtual void update();
	virtual const mat4 &transform();

	virtual Entity *move(const vec3 &);
	virtual Entity *rotate(const vec3 &);
	virtual Entity *lookAt(const vec3 &);
	
	virtual Entity *lock(bool = true);
	virtual Entity *pos(const vec3 &);
	virtual Entity *rot(const vec3 &);
	virtual Entity *vel(const vec3 &);
	virtual Entity *rvel(const vec3 &);
	virtual Entity *collider(Collider *);
	virtual Entity *attach(Entity *, const vec3 &poff, const vec3 &roff);

	virtual bool locked() const;
	virtual const vec3 &pos() const;
	virtual const vec3 &rot() const;
	virtual const vec3 &vel() const;
	virtual const vec3 &rvel() const;
	virtual Collider* collider() const;
	virtual bool collidable() const;
	virtual bool attached() const;
	virtual Entity *attachment() const;

protected:
	bool o_locked;
	bool o_calcd_transform;
	bool o_attached;

	vec3 o_pos;
	vec3 o_rot;
	vec3 o_vel;
	vec3 o_rvel;
	vec3 o_attachment_offsets[2];

	mat4 o_mat_pos;
	mat4 o_mat_rot;
	mat4 o_mat_transform;

	Collider *op_collider;
	Entity *op_attachment;

};

} }
#endif
