/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /mesh_shapes.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

///////////////////////////////////////////////// BoxMesh

BoxMesh::BoxMesh( float s ) : Mesh( mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP, 0xff ) {
	m_width = m_length = m_height = s;
	build();
}

BoxMesh::BoxMesh( float w, float l, float h ) : Mesh( mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP, 0xff ) {
	m_width = w;
	m_length = l;
	m_height = h;
	build();
}

BoxMesh::~BoxMesh() {}

void BoxMesh::build() {
	pushVertices( {
		vec4( m_width/-2.0f, m_height/2.0f, m_length/-2.0f ),	// 0
		vec4( m_width/2.0f, m_height/2.0f, m_length/-2.0f ),	// 1
		vec4( m_width/2.0f, m_height/2.0f, m_length/2.0f ),		// 2
		vec4( m_width/-2.0f, m_height/2.0f, m_length/2.0f ),	// 3
		vec4( m_width/-2.0f, m_height/-2.0f, m_length/-2.0f ),	// 4
		vec4( m_width/2.0f, m_height/-2.0f, m_length/-2.0f ),	// 5
		vec4( m_width/2.0f, m_height/-2.0f, m_length/2.0f ),	// 6
		vec4( m_width/-2.0f, m_height/-2.0f, m_length/2.0f ),	// 7
	} );
	pushNormals( {
		vec3( -1, 1, -1 ),
		vec3( 1, 1, -1 ),
		vec3( 1, 1, 1 ),
		vec3( -1, 1, 1 ),
		vec3( -1, -1, -1 ),
		vec3( 1, -1, -1 ),
		vec3( 1, -1, 1 ),
		vec3( -1, -1, 1 )
	} );
	pushIndices( {
		1, 0, 2, 3, 6, 7, 5, 4,
		0xff,
		2, 6, 1, 5, 0, 4, 3, 7
	} ); }

///////////////////////////////////////////////// FloorMesh

FloorMesh::FloorMesh( float w, float l ) : Mesh( mesh_draw_t::ELEMENT, mesh_shape_t::TRIANGLE_STRIP ) {
	m_width = w;
	m_length = ( l == 0 ? w : l );
	pushVertices( {
		vec4( w/-2.0f, 0, l/-2.0f ),
		vec4( w/2.0f, 0, l/-2.0f ),
		vec4( w/2.0f, 0, l/2.0f ),
		vec4( w/-2.0f, 0, l/2.0f )
	} );
	pushIndices( {
		0, 3, 1, 2
	} );
}

FloorMesh::~FloorMesh() {}



}
