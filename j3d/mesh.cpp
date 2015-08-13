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
	m_draw_t = d;
	m_shape_t = s;
	m_restart_index = restart_index;
	m_has_restart = (m_restart_index > 0);
	m_optimize_2d = false;
	m_built = false;
	mp_buffers = nullptr;
	mp_vertices = nullptr;
	mp_indices = nullptr;
	mp_normals = nullptr;
	m_sz_v = m_sz_n = m_sz_i = 0;
}

Mesh::~Mesh()
{
	if (mp_normals != nullptr)
		delete [] mp_normals;
	if (mp_indices != nullptr)
		delete [] mp_indices;
	if (mp_vertices != nullptr)
		delete [] mp_vertices;
	if (mp_buffers != nullptr)
		delete [] mp_buffers;
}

////////////////////////////////////////
// LOAD

/*
 * vec4
 */

Mesh *Mesh::pushVertex(const vec4 &v)
{
	if (isBuilt() || is2D())
		return this;
	m_vec_v.push_back(v);
	return this;
}

Mesh *Mesh::pushVertices(const vec4 *vs, const unsigned int &len)
{
	if (isBuilt() || is2D())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		m_vec_v.push_back(vs[i]);
	return this;
}

Mesh *Mesh::pushVertices(initializer_list<vec4> vs)
{
	if (isBuilt() || is2D())
		return this;
	for (vec4 v : vs)
		m_vec_v.push_back(v);
	return this;
}

/*
 * vec3
 */

Mesh *Mesh::pushVertex(const vec3 &v)
{
	if (isBuilt() || is2D())
		return this;
	m_vec_v.push_back(vec4(v));
	return this;
}

Mesh *Mesh::pushVertices(const vec3 *vs, const unsigned int &len)
{
	if (isBuilt() || is2D())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		m_vec_v.push_back(vec4(vs[i]));
	return this;
}

Mesh *Mesh::pushVertices(initializer_list<vec3> vs)
{
	if (isBuilt() || is2D())
		return this;
	for (vec3 v : vs)
		m_vec_v.push_back(vec4(v));
	return this;
}

/*
 * vec2
 */

Mesh *Mesh::pushVertex(const vec2 &v)
{
	if (isBuilt())
		return this;
	m_vec_v.push_back(vec4(v));
	m_optimize_2d = true;
	return this;
}

Mesh *Mesh::pushVertices(const vec2 *vs, const unsigned int &len)
{
	if (isBuilt())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		m_vec_v.push_back(vec4(vs[i]));
	m_optimize_2d = true;
	return this;
}

Mesh *Mesh::pushVertices(initializer_list<vec2> vs)
{
	if (isBuilt())
		return this;
	for (vec2 v : vs)
		m_vec_v.push_back(vec4(v));
	m_optimize_2d = true;
	return this;
}

/*
 * normals
 */

Mesh *Mesh::pushNormal(const vec3 &v)
{
	if (isBuilt() || is2D())
		return this;
	m_vec_n.push_back(v);
	return this;
}

Mesh *Mesh::pushNormals(const vec3 *vs, const unsigned int &len)
{
	if (isBuilt() || is2D())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		m_vec_n.push_back(vs[i]);
	return this;
}

Mesh *Mesh::pushNormals(initializer_list<vec3> vs)
{
	if (isBuilt() || is2D())
		return this;
	for (vec3 v : vs)
		m_vec_n.push_back(v);
	return this;
}

/*
 * indices
 */

Mesh *Mesh::pushIndex(const unsigned int &s)
{
	if (isBuilt())
		return this;
	m_vec_i.push_back(s);
	return this;
}

Mesh *Mesh::pushIndices(const unsigned int *ss, const unsigned int &len)
{
	if (isBuilt())
		return this;
	for (unsigned int i = 0; i < len; ++i)
		m_vec_i.push_back(ss[i]);
	return this;
}

Mesh *Mesh::pushIndices(initializer_list<unsigned int> ss)
{
	if (isBuilt())
		return this;
	for (unsigned int s : ss)
		m_vec_i.push_back(s);
	return this;
}

////////////////////////////////////////
// BUILD RENDER

void Mesh::build()
{
	if (isBuilt()) return;
	J3D_DEBUG_PUSH("Mesh build: " << cacheIdFull());
	
	m_built = true;
	unsigned int iter, i;

	glGenVertexArrays(1, &m_vertex_array_id);
	glBindVertexArray(m_vertex_array_id);

	if (!m_optimize_2d) {
		m_sz_v = m_vec_v.size() * 4 * sizeof(GLfloat);
		mp_vertices = new GLfloat[m_vec_v.size() * 4];
	} else {
		m_sz_v = m_vec_v.size() * 2 * sizeof(GLfloat);
		mp_vertices = new GLfloat[m_vec_v.size() * 2];
	}
	J3D_DEBUG_TODO("loading vertices");
	for (iter = 0, i = 0; i < m_vec_v.size(); ++i) {
		mp_vertices[iter++] = (GLfloat)m_vec_v[i].x;
		mp_vertices[iter++] = (GLfloat)m_vec_v[i].y;
		if (m_optimize_2d)
			continue;
		mp_vertices[iter++] = (GLfloat)m_vec_v[i].z;
		mp_vertices[iter++] = (GLfloat)m_vec_v[i].w;
	}
	J3D_DEBUG_TODO_OK;

	bool normals = (!m_optimize_2d && !m_vec_n.empty());
	if (normals) {
		J3D_DEBUG_TODO("loading normals");
		m_sz_n = m_vec_n.size() * 3 * sizeof(GLfloat);
		mp_normals = new GLfloat[m_vec_n.size() * 3];
		for (iter = 0, i = 0; i < m_vec_n.size(); ++i) {
			mp_normals[iter++] = (GLfloat)m_vec_n[i].x;
			mp_normals[iter++] = (GLfloat)m_vec_n[i].y;
			mp_normals[iter++] = (GLfloat)m_vec_n[i].z;
		}
		J3D_DEBUG_TODO_OK;
	}

	if (m_draw_t == mesh_draw_t::ELEMENT) {
		m_sz_i = m_vec_i.size() * sizeof(GLuint);
		mp_indices = new GLuint[m_vec_i.size()];
		J3D_DEBUG_TODO("loading indices");
		for (i = 0; i < m_vec_i.size(); ++i)
			mp_indices[i] = (GLuint)m_vec_i[i];
		J3D_DEBUG_TODO_OK;
		mp_buffers = new GLuint[2];
		glGenBuffers(2, mp_buffers);
	} else {
		mp_buffers = new GLuint[1];
		glGenBuffers(1, mp_buffers);
	}

	J3D_DEBUG_TODO("binding buffer data");
	switch (m_draw_t) {
	case mesh_draw_t::ELEMENT:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mp_buffers[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_sz_i, mp_indices,
				GL_STATIC_DRAW);
	case mesh_draw_t::ARRAY:
		glBindBuffer(GL_ARRAY_BUFFER, mp_buffers[0]);
		if (normals) {
			glBufferData(GL_ARRAY_BUFFER, m_sz_v + m_sz_n, NULL,
					GL_STATIC_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, m_sz_v, mp_vertices);
			glBufferSubData(GL_ARRAY_BUFFER, m_sz_v, m_sz_n, mp_normals);
		} else
			glBufferData(GL_ARRAY_BUFFER, m_sz_v, mp_vertices, GL_STATIC_DRAW);
		break;
	default:
		J3D_DEBUG_TODO_FATAL("invalid draw type " << (int)m_draw_t);
		break;
	}
	J3D_DEBUG_TODO_OK;

	J3D_DEBUG_TODO("setting attrib pointers");
	if (!m_optimize_2d)
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	else
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	if (normals) {
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
				(void *)((uintptr_t)m_sz_v));
		glEnableVertexAttribArray(1);
	}
	J3D_DEBUG_TODO_OK;
	
	J3D_DEBUG_OK("Mesh built");
	J3D_DEBUG_POP;
}

void Mesh::render()
{
	if (!m_built)
		build();

	switch (m_shape_t) {
	case mesh_shape_t::LINE_STRIP:
	case mesh_shape_t::TRIANGLE_STRIP:
		if (m_has_restart) {
			glEnable(GL_PRIMITIVE_RESTART);
			glPrimitiveRestartIndex(m_restart_index);
		} else
			glDisable(GL_PRIMITIVE_RESTART);
		break;
	default:
		break;
	}

	switch (m_draw_t) {
	case mesh_draw_t::ELEMENT:
		glDrawElements(GL_SHAPE_MAP[(int)m_shape_t], m_vec_i.size(),
				GL_UNSIGNED_INT, NULL);
		break;
	case mesh_draw_t::ARRAY:
		glDrawArrays(GL_SHAPE_MAP[(int)m_shape_t], 0, m_vec_v.size());
		break;
	default:
		J3D_DEBUG_FATAL("invalid draw type " << (int)m_draw_t << ": " <<
				cacheIdFull());
		break;
	}
}

////////////////////////////////////////
// GET SET

Mesh *Mesh::optimize2D(bool b) { m_optimize_2d = b; return this; }

bool Mesh::optimize2D() const { return m_optimize_2d; }

////////////////////////////////////////
// EXTRAS

bool Mesh::isBuilt()
{
	if (m_built) {
		J3D_DEBUG_ERROR("Mesh already built: " << cacheIdFull());
		return true;
	}
	return false;
}

bool Mesh::is2D()
{
	if (m_optimize_2d) {
		J3D_DEBUG_ERROR("Mesh is 2D optimized: " << cacheIdFull());
		return true;
	}
	return false;
}

}
