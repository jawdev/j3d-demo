/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/mesh_2d.h
*******************************************************************************/
#ifndef __J3D_MESH_2D_H__
#define __J3D_MESH_2D_H__
namespace j3d {

/*******************************************************************************
* MESH2D
*******************************************************************************/

class Mesh2D : public Mesh {
public:
	Mesh2D(const char *id, mesh_draw_t = mesh_draw_t::ARRAY,
			mesh_shape_t = mesh_shape_t::TRIANGLES,
			unsigned int restart_index = 0);
	virtual ~Mesh2D();
};

}
#endif
