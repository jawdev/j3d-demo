/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /camera.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

//====================================
// INIT
//====================================

Camera::Camera( camera_mode_t mode, camera_proj_t proj, float near, float far ) {
	m_mode = mode;
	m_proj = proj;
	m_near = ( near == 0 ? Settings::render_distance_near : near );
	m_far = ( far == 0 ? Settings::render_distance_far : far );
	reshape();
}

Camera::~Camera() {

}

//====================================
// UPDATE
//====================================

void Camera::reshape() {
	float aspect = (float)Settings::window_width/(float)Settings::window_height;
	switch( m_proj ) {
	case camera_proj_t::NONE:
		m_mat_proj.iden();
		break;
	case camera_proj_t::PERSPECTIVE:
		vmath::perspective( &m_mat_proj, -aspect, aspect, -1, 1, m_near, m_far );
		break;
	default:
		debug::fatal << "(Camera::reshape) invalid projection type: " << (unsigned int)m_proj << debug::flush;
		break;
	}
}

void Camera::update( float dtime ) {
	if( trigger::reshape ) reshape();
	simulate( dtime );
}

mat4 Camera::transform() {
	vmath::translation( &m_mat_translation, -m_position );
	vmath::rotation( &m_mat_rotation, -m_rotation );
	m_mat_transform = m_mat_rotation*m_mat_translation;
	m_mat_transform = m_mat_proj*m_mat_transform;
	return m_mat_transform;
}


}
