/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/mesh.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* MESH
*******************************************************************************/

Mesh::Mesh(const char *id, mesh_draw_t d, mesh_shape_t s,
		unsigned int restart_index) : core::Cacheable(J3D_CACHE_ID, id)
{
	o_draw_t = d;
	o_shape_t = s;
	o_restart_index = restart_index;
	o_has_restart = (o_restart_index > 0);
	o_built = false;
	op_buffers = nullptr;
	op_vertices = nullptr;
	op_indices = nullptr;
	op_normals = nullptr;
	o_sz_v = o_sz_n = o_sz_i = 0;
}

Mesh::~Mesh()
{
	if (op_normals != nullptr)
		delete [] op_normals;
	if (op_indices != nullptr)
		delete [] op_indices;
	if (op_vertices != nullptr)
		delete [] op_vertices;
	if (op_buffers != nullptr)
		delete [] op_buffers;
}

////////////////////////////////////////
// LOAD

Mesh *Mesh::pushVertex(const vec4 &v)
{
	if (built())
		return this;
	o_vec_v.push_back(v);
	return this;
}

Mesh *Mesh::pushVertices(const vec4 *vs, const unsigned int &len)
{
	if (built())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		o_vec_v.push_back(vs[i]);
	return this;
}

Mesh *Mesh::pushVertices(initializer_list<vec4> vs)
{
	if (built())
		return this;
	for (vec4 v : vs)
		o_vec_v.push_back(v);
	return this;
}

Mesh *Mesh::pushNormal(const vec3 &v)
{
	if (built())
		return this;
	o_vec_n.push_back(v);
	return this;
}

Mesh *Mesh::pushNormals(const vec3 *vs, const unsigned int &len)
{
	if (built())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		o_vec_n.push_back(vs[i]);
	return this;
}

Mesh *Mesh::pushNormals(initializer_list<vec3> vs)
{
	if (built())
		return this;
	for (vec3 v : vs)
		o_vec_n.push_back(v);
	return this;
}

Mesh *Mesh::pushIndex(const unsigned int &s)
{
	if (built())
		return this;
	o_vec_i.push_back(s);
	return this;
}

Mesh *Mesh::pushIndices(const unsigned int *ss, const unsigned int &len)
{
	if (built())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		o_vec_i.push_back(ss[i]);
	return this;
}

Mesh *Mesh::pushIndices(initializer_list<unsigned int> ss)
{
	if (built())
		return this;
	for (unsigned int s : ss)
		o_vec_i.push_back(s);
	return this;
}

////////////////////////////////////////
// BUILD RENDER

void Mesh::build()
{
	if (built()) return;
	o_built = true;
	unsigned int iter, i;

	glGenVertexArrays(1, &o_vertex_array_id);
	glBindVertexArray(o_vertex_array_id);
	o_sz_v = o_vec_v.size() * 4 * sizeof(GLfloat);
	
	op_vertices = new GLfloat[o_vec_v.size() * 4];
	for (iter = 0, i = 0; i < o_vec_v.size(); ++i) {
		op_vertices[iter++] = (GLfloat)o_vec_v[i].x;
		op_vertices[iter++] = (GLfloat)o_vec_v[i].y;
		op_vertices[iter++] = (GLfloat)o_vec_v[i].z;
		op_vertices[iter++] = (GLfloat)o_vec_v[i].w;
	}

	bool normals = !o_vec_n.empty();
	if (normals) {
		J3D_DEBUG_TODO("configuring normals: " << cacheIdFull());
		o_sz_n = o_vec_n.size() * 3 * sizeof(GLfloat);
		op_normals = new GLfloat[o_vec_n.size() * 3];
		for (iter = 0, i = 0; i < o_vec_n.size(); ++i) {
			op_normals[iter++] = (GLfloat)o_vec_n[i].x;
			op_normals[iter++] = (GLfloat)o_vec_n[i].y;
			op_normals[iter++] = (GLfloat)o_vec_n[i].z;
		}
	}

	if (o_draw_t == mesh_draw_t::ELEMENT) {
		o_sz_i = o_vec_i.size() * sizeof(GLuint);
		op_indices = new GLuint[o_vec_i.size()];
		for (i = 0; i < o_vec_i.size(); ++i)
			op_indices[i] = (GLuint)o_vec_i[i];
		op_buffers = new GLuint[2];
		glGenBuffers(2, op_buffers);
	} else {
		op_buffers = new GLuint[1];
		glGenBuffers(1, op_buffers);
	}

	switch (o_draw_t) {
	case mesh_draw_t::ELEMENT:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, op_buffers[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, o_sz_i, op_indices,
				GL_STATIC_DRAW);
	case mesh_draw_t::ARRAY:
		glBindBuffer(GL_ARRAY_BUFFER, op_buffers[0]);
		if (normals) {
			glBufferData(GL_ARRAY_BUFFER, o_sz_v + o_sz_n, NULL,
					GL_STATIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, o_sz_v, op_vertices);
			glBufferSubData(GL_ARRAY_BUFFER, o_sz_v, o_sz_n, op_normals);
		} else
			glBufferData(GL_ARRAY_BUFFER, o_sz_v, op_vertices, GL_STATIC_DRAW);
		break;
	default:
		J3D_DEBUG_FATAL("invalid draw type " << (int)o_draw_t << ": " <<
				cacheIdFull());
		break;
	}

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	if (normals) {
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
				(void *)((uintptr_t)o_sz_v));
		glEnableVertexAttribArray(1);
	}
	
	J3D_DEBUG_OK("Mesh built: " << cacheIdFull());
}

void Mesh::render()
{
	if (!o_built)
		build();

	switch (o_shape_t) {
	case mesh_shape_t::LINE_STRIP:
	case mesh_shape_t::TRIANGLE_STRIP:
		if (o_has_restart) {
			glEnable(GL_PRIMITIVE_RESTART);
			glPrimitiveRestartIndex(o_restart_index);
		} else
			glDisable(GL_PRIMITIVE_RESTART);
		break;
	default:
		break;
	}

	switch (o_draw_t) {
	case mesh_draw_t::ELEMENT:
		glDrawElements(GL_SHAPE_MAP[(int)o_shape_t], o_vec_i.size(),
				GL_UNSIGNED_INT, NULL);
		break;
	case mesh_draw_t::ARRAY:
		glDrawArrays(GL_SHAPE_MAP[(int)o_shape_t], 0, o_vec_v.size());
		break;
	default:
		J3D_DEBUG_FATAL("invalid draw type " << (int)o_draw_t << ": " <<
				cacheIdFull());
		break;
	}
}

////////////////////////////////////////
// EXTRAS

bool Mesh::built()
{
	if (o_built) {
		J3D_DEBUG_ERROR("Mesh already built: " << cacheIdFull());
		return true;
	}
	return false;
}

}
