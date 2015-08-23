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

Object::Object(const string &mesh_id) :
		base::Entity()
{
	init(mesh_id);
}

Object::Object(const string &mesh_id, const string &shader_id) :
		base::Entity(shader_id)
{
	init(mesh_id);
}

Object::~Object() {}

void Object::init(const string &mesh_id)
{
	if (!J3D_CACHE2(exists, Mesh, mesh_id))
		J3D_DEBUG_FATAL("Mesh could not be found: " << mesh_id);
	mp_mesh = J3D_CACHE_GET(Mesh, mesh_id);
	aabb(mp_mesh->min(), mp_mesh->max());
}

void Object::update()
{
	base::Entity::update();
}

void Object::render()
{
	mp_mesh->render();
}

}
