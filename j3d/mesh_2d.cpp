/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/mesh_2d.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* MESH2D
*******************************************************************************/

Mesh2D::Mesh2D(const char *id, mesh_draw_t d, mesh_shape_t s,
		unsigned int restart_index) : Mesh(id, d, s, restart_index)
{
	optimize2D();
}

Mesh2D::~Mesh2D() {}

}
