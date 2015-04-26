/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /mesh.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

///////////////////////////////////////////////// Mesh

Mesh::Mesh( mesh_draw_t draw_type, mesh_shape_t shape_type, unsigned int restart_index ) {
	m_draw_type = draw_type;
	m_shape_type = shape_type;
	m_restart_index = restart_index;
	m_has_restart = ( m_restart_index > 0 );
	m_bound = false;
	mp_vertices = nullptr;
	mp_normals = nullptr;
	mp_indices = nullptr;
	mp_buffer = nullptr;
}

Mesh::~Mesh() {
	SAFE_DELETE( mp_indices );
	SAFE_DELETE( mp_normals );
	SAFE_DELETE( mp_vertices );
	SAFE_DELETE( mp_buffer );
}

//=====================================
// LOAD
//=====================================

Mesh* Mesh::pushVertex( const vec4& v ) {
	if( m_bound ) debug::warn << "(Mesh::pushVertex) mesh has already been built" << debug::flush;
	m_vertex_vector.push_back( v );
	return this;
}

Mesh* Mesh::pushVertices( unsigned int c, vec4* vlist ) {
	if( m_bound ) debug::warn << "(Mesh::pushVertices) mesh has already been built" << debug::flush;
	for( unsigned int i = 0; i < c; i++ ) m_vertex_vector.push_back( vlist[i] );
	return this;
}

Mesh* Mesh::pushVertices( initializer_list<vec4> vlist ) {
	for( vec4 v : vlist ) m_vertex_vector.push_back( v );
	return this;
}

Mesh* Mesh::pushNormal( const vec3& v ) {
	if( m_bound ) debug::warn << "(Mesh::pushNormal) mesh has already been built" << debug::flush;
	m_normal_vector.push_back( v );
	return this;
}

Mesh* Mesh::pushNormals( unsigned int c, vec3* vlist ) {
	if( m_bound ) debug::warn << "(Mesh::pushNormals) mesh has already been built" << debug::flush;
	for( unsigned int i = 0; i < c; i++ ) m_normal_vector.push_back( vlist[i] );
	return this;
}

Mesh* Mesh::pushNormals( initializer_list<vec3> vlist ) {
	for( vec3 v : vlist ) m_normal_vector.push_back( v );
	return this;
}

Mesh* Mesh::pushIndex( const unsigned short& i ) {
	if( m_bound ) debug::warn << "(Mesh::pushIndex) mesh has already been built" << debug::flush;
	m_index_vector.push_back( i );
	return this;
}

Mesh* Mesh::pushIndices( unsigned int c, unsigned short* ilist ) {
	if( m_bound ) debug::warn << "(Mesh::pushIndices) mesh has already been built" << debug::flush;
	for( unsigned int i = 0; i < c; i++ ) m_index_vector.push_back( ilist[i] );
	return this;
}

Mesh* Mesh::pushIndices( initializer_list<unsigned short> ilist ) {
	for( unsigned short i : ilist ) m_index_vector.push_back( i );
	return this;
}

//=====================================
// BIND
//=====================================

void Mesh::bind() {
	if( m_bound ) debug::warn << "(Mesh::bind) binding again" << debug::flush;

	glGenVertexArrays( 1, &m_vertex_array_id );
	glBindVertexArray( m_vertex_array_id );
	m_vertex_size = m_vertex_vector.size()*4*sizeof( GLfloat );

	mp_vertices = new GLfloat[m_vertex_vector.size()*4];
	unsigned int iter = 0;
	for( unsigned int i = 0; i < m_vertex_vector.size(); i++ ) {
		mp_vertices[iter++] = (GLfloat)m_vertex_vector[i].x;
		mp_vertices[iter++] = (GLfloat)m_vertex_vector[i].y;
		mp_vertices[iter++] = (GLfloat)m_vertex_vector[i].z;
		mp_vertices[iter++] = (GLfloat)m_vertex_vector[i].w;
	}

	bool normals = ( m_normal_vector.size() > 0 );
	if( normals ) {
		m_normal_size = m_normal_vector.size()*3*sizeof( GLfloat );
		mp_normals = new GLfloat[m_normal_vector.size()*3];
		iter = 0;
		for( unsigned int i = 0; i < m_normal_vector.size(); i++ ) {
			mp_normals[iter++] = (GLfloat)m_normal_vector[i].x;
			mp_normals[iter++] = (GLfloat)m_normal_vector[i].y;
			mp_normals[iter++] = (GLfloat)m_normal_vector[i].z;
		}
	}
	
	if( m_draw_type == mesh_draw_t::ELEMENT ) {
		m_index_size = m_index_vector.size()*sizeof( GLushort );
		mp_indices = new GLushort[m_index_vector.size()];
		for( unsigned int i = 0; i < m_index_vector.size(); i++ ) mp_indices[i] = (GLushort)m_index_vector[i];
		mp_buffer = new GLuint[2];
		glGenBuffers( 2, mp_buffer );
	} else {
		mp_buffer = new GLuint[1];
		glGenBuffers( 1, mp_buffer );
	}

	switch( m_draw_type ) {
	case mesh_draw_t::ELEMENT:
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mp_buffer[1] );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_index_size, mp_indices, GL_STATIC_DRAW );
	case mesh_draw_t::ARRAY:
		glBindBuffer( GL_ARRAY_BUFFER, mp_buffer[0] );
		if( normals ) {
			glBufferData( GL_ARRAY_BUFFER, m_vertex_size+m_normal_size, NULL, GL_STATIC_DRAW );
			glBufferSubData( GL_ARRAY_BUFFER, 0, m_vertex_size, mp_vertices );
			glBufferSubData( GL_ARRAY_BUFFER, m_vertex_size, m_normal_size, mp_normals );
		} else glBufferData( GL_ARRAY_BUFFER, m_vertex_size, mp_vertices, GL_STATIC_DRAW );
		break;
	default:
		debug::fatal << "(Mesh::bind) invalid mesh draw type: " << (unsigned int)m_draw_type << debug::flush;
		break;
	}

	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 0, 0 );
	glEnableVertexAttribArray( 0 );
	if( normals ) {
		//glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (void*)(m_vertex_vector.size()) );
		glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (void*)( (long)m_vertex_size ) );
		glEnableVertexAttribArray( 1 );
	}
	
	m_bound = true;
}

void Mesh::render() {
	if( !m_bound ) bind();

	//glVertexAttrib3fv( 1, vec3( 1, 0, 1 ).glfloat() );

	switch( m_shape_type ) {
	case mesh_shape_t::LINE_STRIP:
	case mesh_shape_t::TRIANGLE_STRIP:
		if( m_has_restart ) {
			glEnable( GL_PRIMITIVE_RESTART );
			glPrimitiveRestartIndex( m_restart_index );
		} else glDisable( GL_PRIMITIVE_RESTART );
	default:
		break;
	}

	switch( m_draw_type ) {
	case mesh_draw_t::ELEMENT:
		glDrawElements( GL_SHAPE_MAP[(unsigned int)m_shape_type], m_index_vector.size(), GL_UNSIGNED_SHORT, NULL );
		break;
	case mesh_draw_t::ARRAY:
		glDrawArrays( GL_SHAPE_MAP[(unsigned int)m_shape_type], 0, m_vertex_vector.size() );
		break;
	default:
		break;
	}

}


}
