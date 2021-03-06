/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/base/entity_2d.h
*******************************************************************************/
#ifndef __J3D_BASE_ENTITY_2D_H__
#define __J3D_BASE_ENTITY_2D_H__
namespace j3d { namespace base {

/*******************************************************************************
* ENTITY2D
*******************************************************************************/

class Entity2D : public EntityBase<vec2> {
public:
	Entity2D();
	Entity2D(string shader_id);
	virtual ~Entity2D();
};

} }
#endif
