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

	Mesh *pushVertex(const vec3 &);
	Mesh *pushVertices(const vec3 *, const unsigned int &len);
	Mesh *pushVertices(initializer_list<vec3>);

	Mesh *pushVertex(const vec2 &);
	Mesh *pushVertices(const vec2 *, const unsigned int &len);
	Mesh *pushVertices(initializer_list<vec2>);

	Mesh *pushNormal(const vec3 &);
	Mesh *pushNormals(const vec3 *, const unsigned int &len);
	Mesh *pushNormals(initializer_list<vec3>);

	Mesh *pushIndex(const unsigned int &);
	Mesh *pushIndices(const unsigned int *, const unsigned int &len);
	Mesh *pushIndices(initializer_list<unsigned int>);

	virtual void build();
	virtual void bind();
	virtual void render();

	Mesh *optimize2D(bool = true);
	
	bool optimize2D() const;
	const vec3 &min() const;
	const vec3 &max() const;

private:
	bool isBuilt();
	bool is2D();
	void loadMinMax(const vec3 &v);
	
private:
	mesh_draw_t m_draw_t;
	mesh_shape_t m_shape_t;
	bool m_optimize_2d;
	unsigned int m_restart_index;
	bool m_has_restart;
	bool m_built;
	bool m_has_normals;
	vector<vec4> m_vec_v;
	vector<vec3> m_vec_n;
	vector<unsigned int> m_vec_i;
	GLuint m_vertex_array_id;
	GLuint *mp_buffers;
	GLfloat *mp_vertices;
	GLuint *mp_indices;
	GLfloat *mp_normals;
	unsigned int m_sz_v;
	unsigned int m_sz_n;
	unsigned int m_sz_i;
	vec3 m_vmin;
	vec3 m_vmax;

};

}
#endif
