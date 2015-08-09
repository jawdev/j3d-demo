/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/display.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

Display::Display()
{
	glutInit(&engine::setup()->argc, engine::setup()->argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitWindowSize(engine::setup()->window_width,
			engine::setup()->window_height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(engine::setup()->window_title.c_str());
	glewExperimental = GL_TRUE;
	if (glewInit())
		J3D_DEBUG_FATAL("unable to initialize GLEW");

	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	if (J3D_CACHE_EXISTS(core::Renderbuffer)) 
		J3D_CACHE_ACTIVE(core::Renderbuffer)->bind();
	else
		(new core::Renderbuffer("primary"))->bind();
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Display::~Display() {}

////////////////////////////////////////
// CORE

void Display::loop()
{
	glutMainLoop();
}

void Display::reshape(int w, int h)
{
	util::cycle::triggers.reshape = true;
	glViewport(0, 0, w, h);
	engine::setup()->window_width = w;
	engine::setup()->window_height = h;
}

void Display::display()
{
	engine::update();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void Display::on_reshape(int w, int h)
{
	engine::display()->reshape(w, h);
}

void Display::on_display()
{
	engine::display()->display();
}

}
