/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/object.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* OBJECT
*******************************************************************************/

Object::Object(const char *mesh_id) : core::Entity()
{
	if (!J3D_CACHE_HAS(Mesh, mesh_id))
		J3D_DEBUG_FATAL("mesh could not be found: " << mesh_id);
	op_mesh = J3D_CACHE_GET(Mesh, mesh_id);
}

Object::~Object() {}

void Object::update()
{
	spatialize();
}

void Object::render()
{
	op_mesh->render();
}

}
