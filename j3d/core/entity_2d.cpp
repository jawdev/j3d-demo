/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/entity_2d.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* ENTITY2D
*******************************************************************************/

Entity2D::Entity2D() :
		EntityBase<vec2>()
{}

Entity2D::Entity2D(string shader_id) :
		EntityBase<vec2>(shader_id)
{}

Entity2D::~Entity2D() {}

} }
