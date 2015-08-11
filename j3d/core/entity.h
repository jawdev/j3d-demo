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

class Entity : public EntityBase<vec3> {
public:
	Entity(bool locked = false);
	virtual ~Entity();

	virtual const mat4 &transform();
	virtual Entity *lookAt(const vec3 &);
	
	virtual Entity *lock(bool = true);

protected:
	bool o_calcd_transform;
	mat4 o_mat_pos;
	mat4 o_mat_rot;
	mat4 o_mat_transform;

};

} }
#endif
