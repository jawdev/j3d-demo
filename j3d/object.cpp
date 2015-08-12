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

Object::Object(string mesh_id) :
		core::Entity()
{
	if (!J3D_CACHE2(exists, Mesh, mesh_id))
		J3D_DEBUG_FATAL("Mesh could not be found: " << mesh_id);
	mp_mesh = J3D_CACHE_GET(Mesh, mesh_id);
}

Object::Object(string mesh_id, string shader_id) :
		core::Entity(shader_id)
{
	if (!J3D_CACHE2(exists, Mesh, mesh_id))
		J3D_DEBUG_FATAL("Mesh could not be found: " << mesh_id);
	mp_mesh = J3D_CACHE_GET(Mesh, mesh_id);
}

Object::~Object() {}

void Object::update()
{
	core::Entity::update();
}

void Object::render()
{
	mp_mesh->render();
}

}
