/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /control.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

///////////////////////////////////////////////// Control

bool Control::m_key_down[Control::K];
bool Control::m_mouse_down[Control::M];
bool Control::m_init_complete = false;
bool Control::m_recording = false;
float Control::m_record_time = 0.0f;
int Control::m_last_x = 0;
int Control::m_last_y = 0;
int Control::m_new_x = 0;
int Control::m_new_y = 0;

void Control::init() {
	if( m_init_complete ) debug::warn << "(Control::init) Control has already been initialized" << debug::flush;

	glutIgnoreKeyRepeat( 1 );
	glutKeyboardFunc( callbackKeyDown );
	glutKeyboardUpFunc( callbackKeyUp );
	glutSpecialFunc( callbackSpecialDown );
	glutSpecialUpFunc( callbackSpecialUp );
	for( unsigned int i = 0; i < K; i++ ) m_key_down[i] = false;

	glutMouseFunc( callbackMouseClick );
	glutPassiveMotionFunc( callbackMouseMove );
	for( unsigned int i = 0; i < M; i++ ) m_mouse_down[i] = false;
	
	m_init_complete = true;
}

//====================================
// CALLBACK
//====================================

void Control::callbackKeyDown( unsigned char key, int x, int y ) {
	debug::code << "K-DN: " << key << " {" << x << "," << y << "}" << debug::flush;
	m_key_down[(unsigned int)key] = true;
	Engine::scene->onKeyDown( key, x, y );
}

void Control::callbackKeyUp( unsigned char key, int x, int y ) {
	debug::code << "K-UP: " << key << " {" << x << "," << y << "}" << debug::flush;
	m_key_down[(unsigned int)key] = false;
	Engine::scene->onKeyUp( key, x, y );
}

void Control::callbackSpecialDown( int key, int x, int y ) {
	debug::code << "S-DN: " << key << " {" << x << "," << y << "}" << debug::flush;
	m_key_down[(unsigned int)(key+S)] = true;
	Engine::scene->onSpecialDown( key, x, y );
}

void Control::callbackSpecialUp( int key, int x, int y ) {
	debug::code << "S-UP: " << key << " {" << x << "," << y << "}" << debug::flush;
	m_key_down[(unsigned int)(key+S)] = false;
	Engine::scene->onSpecialUp( key, x, y );
}

void Control::callbackMouseClick( int button, int state, int x, int y ) {
	unsigned int btn = (unsigned int)button;
	switch( state ) {
	case GLUT_DOWN:
		m_mouse_down[btn] = true;
		Engine::scene->onMouseDown( button, x, y );
		break;
	case GLUT_UP:
		m_mouse_down[btn] = false;
		Engine::scene->onMouseUp( button, x, y );
		break;
	default:
		debug::warn << "(Control::callbackMouseClick) unrecognized mouse state: " << state << debug::flush;
		break;
	}
}

void Control::callbackMouseMove( int x, int y ) {
	m_recording = true;
	m_new_x = x;
	m_new_y = y;
}

void Control::update( float dtime ) {
	if( m_recording ) {
		m_record_time += dtime;
		if( m_record_time > Settings::mouse_buffer_time ) {
			m_record_time = 0;
			Engine::scene->onMouseMove( m_new_x, m_new_y, m_last_x, m_last_y );
			m_last_x = m_new_x;
			m_last_y = m_new_y;
			m_recording = false;
		}
	}
}

//====================================
// TEST
//====================================

bool Control::keyDown( unsigned char key ) { return m_key_down[(unsigned int)key]; }
bool Control::specialDown( int key ) { return m_key_down[(unsigned int)key]; }

bool Control::keysDown( initializer_list<unsigned char> keys ) {
	for( unsigned char key : keys ) if( !keyDown( key ) ) return false;
	return true;
}

bool Control::specialsDown( initializer_list<int> keys ) {
	for( int key : keys ) if( !specialDown( key ) ) return false;
	return true;
}

bool Control::combo( initializer_list<int> specials, initializer_list<unsigned char> keys ) {
	return ( specialsDown( specials ) && keysDown( keys ) );
}




}
