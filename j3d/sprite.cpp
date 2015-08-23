/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/sprite.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* SPRITE
*******************************************************************************/

Sprite::Sprite(const char *mesh_id) : base::Entity2D()
{
	if (!J3D_CACHE2(exists, Mesh2D, mesh_id))
		J3D_DEBUG_FATAL("Mesh could not be found: " << mesh_id);
	mp_mesh = J3D_CACHE_GET(Mesh2D, mesh_id);
	if (!mp_mesh->optimize2D())
		J3D_DEBUG_FATAL("Mesh must be 2D optimized: " <<
				mp_mesh->cacheIdFull());
}

Sprite::~Sprite() {}

void Sprite::update()
{
	base::Entity2D::update();
}

void Sprite::render()
{
	mp_mesh->render();
}

}
