/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /display.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

//====================================
// MAIN
//====================================

Display::Display() {
	glutInit( &Engine::argc, Engine::argv );
	glutInitDisplayMode( GLUT_RGBA );
	glutInitContextVersion( 4, 3 );
	glutInitContextProfile( GLUT_CORE_PROFILE );
	glutInitWindowSize( Settings::window_width, Settings::window_height );
	glutInitWindowPosition( ( glutGet( GLUT_SCREEN_WIDTH )-Settings::window_width )/2.0f, ( glutGet( GLUT_SCREEN_HEIGHT )-Settings::window_height )/2.0f );
	glutCreateWindow( Settings::window_title );
	glewExperimental = GL_TRUE;
	if( glewInit() ) Debug::fatal( "(Display::Display) unable to initialize GLEW" );
	glutReshapeFunc( callbackReshape );
	glutDisplayFunc( callbackDisplay );
	atexit( callbackQuit );
	glutSetCursor( Settings::glut_cursor );
	mp_renderbuffer = new Renderbuffer();
	mp_renderbuffer->bind();
}

Display::~Display() {
	SAFE_DELETE( mp_renderbuffer );
}

void Display::mainLoop() {
	glutMainLoop();
}

//=====================================
// CALLBACKS
//=====================================

void Display::callbackReshape( int w, int h ) {
	glViewport( 0, 0, w, h );
	Settings::window_width = w;
	Settings::window_height = h;
	Engine::display->renderbuffer()->reshape( w, h );
}

void Display::callbackDisplay() {
	Engine::cycle();
	Engine::display->renderbuffer()->blit();
	glutPostRedisplay();
}

void Display::callbackQuit() {
	Engine::quit();
}

//=====================================
// RENDER BUFFERS
//=====================================

Renderbuffer* Display::renderbuffer() {
	return mp_renderbuffer;
}

}
