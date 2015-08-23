/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* demo/mesh_test.cpp
*******************************************************************************/
#include "inc.h"

/*******************************************************************************
* MESHTEST
*******************************************************************************/

MeshTest::MeshTest(const char *id) :
		Mesh(id, mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP)
{
	float w = 10.0f;
	pushVertices({
		vec4(w / -2.0f, 0, w / -2.0f),
		vec4(w /  2.0f, 0, w / -2.0f),
		vec4(w /  2.0f, 0, w /  2.0f),
		vec4(w / -2.0f, 0, w /  2.0f)
	});
	pushNormals({
		vec3(0, 1, 0),
		vec3(0, 1, 0),
		vec3(0, 1, 0),
		vec3(0, 1, 0)
	});
	pushIndices({0, 3, 1, 2});
}

MeshTest::~MeshTest() {}
