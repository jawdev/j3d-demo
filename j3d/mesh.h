/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /mesh.h
******************************************************************************/
#ifndef J3D_MESH_H_
#define J3D_MESH_H_
namespace j3d {

enum class mesh_draw_t : unsigned int {
	ARRAY = 0,
	ELEMENT,
	_length
};

enum class mesh_shape_t : unsigned int {
	POINTS = 0,
	LINES,
	LINE_STRIP,
	LINE_LOOP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN,
	_length
};

static const GLuint GL_SHAPE_MAP[(unsigned int)mesh_shape_t::_length] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN
};

///////////////////////////////////////////////// Mesh

class Mesh {
public:
	Mesh( mesh_draw_t = mesh_draw_t::ARRAY, mesh_shape_t = mesh_shape_t::TRIANGLES, unsigned int restart_index = 0 );
	virtual ~Mesh();

	//=====================================
	// LOAD
	//=====================================

	Mesh* pushVertex( const vec4& );
	Mesh* pushVertices( unsigned int, vec4* );
	Mesh* pushVertices( initializer_list<vec4> vlist );
	Mesh* pushIndex( const unsigned short& );
	Mesh* pushIndices( unsigned int, unsigned short* );
	Mesh* pushIndices( initializer_list<unsigned short> ilist );

	//=====================================
	// BIND
	//=====================================

	void bind();
	void render();

protected:
	mesh_draw_t m_draw_type;
	mesh_shape_t m_shape_type;
	unsigned int m_restart_index;
	bool m_has_restart;
	bool m_bound;
	vector<vec4> m_vertex_vector;
	vector<unsigned short> m_index_vector;
	GLuint m_vertex_array_id;
	GLuint* mp_buffer;
	GLfloat* mp_vertices;
	GLushort* mp_indices;
	unsigned int m_vertex_size;
	unsigned int m_index_size;
};

}
#endif
