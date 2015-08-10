/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/display.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

Display::Display()
{
	glutInit(&engine::config()->argc, engine::config()->argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitWindowSize(engine::config()->window_width,
			engine::config()->window_height);
	glutInitWindowPosition(engine::config()->window_start_x,
			engine::config()->window_start_y);
	glutCreateWindow(engine::config()->window_title.c_str());
	glewExperimental = GL_TRUE;
	if (glewInit())
		J3D_DEBUG_FATAL("unable to initialize GLEW");

	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	if (J3D_CACHE_EXISTS(Renderbuffer)) 
		J3D_CACHE_ACTIVE(Renderbuffer)->bind();
	else
		(new Renderbuffer("j3d_default"))->bind();
	
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
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
	J3D_DEBUG_INFO("reshape");
	cycle::triggers.reshape = true;
	glViewport(0, 0, w, h);
	engine::config()->window_width = w;
	engine::config()->window_height = h;
	J3D_CACHE_ACTIVE(Renderbuffer)->reshape(w, h);
}

void Display::display()
{
	J3D_CACHE_ACTIVE(Renderbuffer)->bind();
	engine::update();
	J3D_CACHE_ACTIVE(Renderbuffer)->blit();
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

} }
