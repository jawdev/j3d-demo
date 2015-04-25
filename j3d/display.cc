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
	if( glewInit() ) debug::fatal << "(Display::Display) unable to initialize GLEW" << debug::flush;
	glutReshapeFunc( callbackReshape );
	glutDisplayFunc( callbackDisplay );
	atexit( callbackQuit );
	glutSetCursor( Settings::glut_cursor );
	if( Cache::renderbuffers()->empty() ) Cache::renderbuffers()->push( new Renderbuffer )->bind();
}

Display::~Display() {
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
	Cache::renderbuffer()->reshape( w, h );
}

void Display::callbackDisplay() {
	Engine::cycle();
	Cache::renderbuffer()->blit();
	glutPostRedisplay();
}

void Display::callbackQuit() {
	Engine::quit();
}

}
