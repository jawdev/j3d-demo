/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/mesh_shapes.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* BoxMesh
*******************************************************************************/

BoxMesh::BoxMesh(const char *id, float s)
		: Mesh(id, mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP, 0xff)
{
	m_width = m_length = m_height = s;
	create();
}

BoxMesh::BoxMesh(const char *id, float w, float l, float h)
		: Mesh(id, mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP, 0xff)
{
	m_width = w;
	m_length = l;
	m_height = h;
	create();
}

BoxMesh::~BoxMesh() {}

void BoxMesh::create()
{
	pushVertices({
		vec4(m_width / -2.0f, m_height /  2.0f, m_length / -2.0f),
		vec4(m_width /  2.0f, m_height /  2.0f, m_length / -2.0f),
		vec4(m_width /  2.0f, m_height /  2.0f, m_length /  2.0f),
		vec4(m_width / -2.0f, m_height /  2.0f, m_length /  2.0f),
		vec4(m_width / -2.0f, m_height / -2.0f, m_length / -2.0f),
		vec4(m_width /  2.0f, m_height / -2.0f, m_length / -2.0f),
		vec4(m_width /  2.0f, m_height / -2.0f, m_length /  2.0f),
		vec4(m_width / -2.0f, m_height / -2.0f, m_length /  2.0f),
	});
	pushNormals({
		vec3(-1,  1, -1),
		vec3( 1,  1, -1),
		vec3( 1,  1,  1),
		vec3(-1,  1,  1),
		vec3(-1, -1, -1),
		vec3( 1, -1, -1),
		vec3( 1, -1,  1),
		vec3(-1, -1,  1)
	});
	pushIndices({
		2, 6, 1, 5, 0, 4, 3, 7,
		0xff,
		1, 0, 2, 3, 6, 7, 5, 4,
		//5, 0, 4, 3, 7, 2, 6, 1,
	});
}

float BoxMesh::size() const { return m_width; }
float BoxMesh::width() const { return m_width; }
float BoxMesh::length() const { return m_length; }
float BoxMesh::height() const { return m_height; }

/*******************************************************************************
* FloorMesh
*******************************************************************************/

FloorMesh::FloorMesh(const char *id, float w, float l)
		: Mesh(id, mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP)
{
	m_width = w;
	m_length = (l == 0 ? m_width : l);
	pushVertices({
		vec4(w / -2.0f, l / -2.0f),
		vec4(w /  2.0f, l / -2.0f),
		vec4(w /  2.0f, l /  2.0f),
		vec4(w / -2.0f, l /  2.0f)
	});
	pushIndices({0, 3, 1, 2});
}

FloorMesh::~FloorMesh() {}

float FloorMesh::width() const { return m_width; }
float FloorMesh::length() const { return m_length; }

/*******************************************************************************
* RECTMESH
*******************************************************************************/

RectMesh::RectMesh(const char *id, float t, float r, float b, float l)
		: Mesh2D(id, mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP)
{
	m_rect[T] = t;
	m_rect[R] = r;
	m_rect[B] = b;
	m_rect[L] = l;

	pushVertices({
		vec2(l, t),
		vec2(r, t),
		vec2(r, b),
		vec2(l, b)
	});
	pushIndices({0, 3, 1, 2});
}

RectMesh::~RectMesh() {}

float RectMesh::top() const { return m_rect[T]; }
float RectMesh::right() const { return m_rect[R]; }
float RectMesh::bottom() const { return m_rect[B]; }
float RectMesh::left() const { return m_rect[L]; }

}
