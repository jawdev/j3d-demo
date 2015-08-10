/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/mesh.h
*******************************************************************************/
#ifndef __J3D_MESH_H__
#define __J3D_MESH_H__
namespace j3d {

enum class mesh_draw_t : int {
	ARRAY = 0,
	ELEMENT,
	_len
};

enum class mesh_shape_t : int {
	POINTS = 0,
	LINES,
	LINE_STRIP,
	LINE_LOOP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN,
	_len
};

const GLuint GL_SHAPE_MAP[(int)mesh_shape_t::_len] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN
};

/*******************************************************************************
* MESH
*******************************************************************************/

class Mesh : public core::Cacheable {
public:
	static const char constexpr *J3D_CACHE_ID = "mesh";

public:
	Mesh(const char *id, mesh_draw_t = mesh_draw_t::ARRAY,
			mesh_shape_t = mesh_shape_t::TRIANGLES,
			unsigned int restart_index = 0);
	virtual ~Mesh();
	
	Mesh *pushVertex(const vec4 &);
	Mesh *pushVertices(const vec4 *, const unsigned int &len);
	Mesh *pushVertices(initializer_list<vec4>);

	Mesh *pushNormal(const vec3 &);
	Mesh *pushNormals(const vec3 *, const unsigned int &len);
	Mesh *pushNormals(initializer_list<vec3>);

	Mesh *pushIndex(const unsigned short &);
	Mesh *pushIndices(const unsigned short *, const unsigned int &len);
	Mesh *pushIndices(initializer_list<unsigned short>);

	void build();
	void render();

private:
	bool built();
	
protected:
	mesh_draw_t o_draw_t;
	mesh_shape_t o_shape_t;
	unsigned int o_restart_index;
	bool o_has_restart;
	bool o_built;
	vector<vec4> o_vec_v;
	vector<vec3> o_vec_n;
	vector<unsigned short> o_vec_i;
	GLuint o_vertex_array_id;
	GLuint *op_buffers;
	GLfloat *op_vertices;
	GLushort *op_indices;
	GLfloat *op_normals;
	unsigned int o_sz_v;
	unsigned int o_sz_n;
	unsigned int o_sz_i;

};

}
#endif
