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
	J3D_DEBUG_TODO("creating glut window");
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
		J3D_DEBUG_TODO_FATAL("unable to initialize GLEW");
	J3D_DEBUG_TODO_OK;

	J3D_DEBUG_TODO("loading glut display callbacks");
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);
	J3D_DEBUG_TODO_OK;

	J3D_DEBUG_TODO("setting opengl display options");
	glClearColor(0, 0, 0, 0);
	glEnable(GL_BLEND);
	glEnable(GL_MULTISAMPLE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	J3D_DEBUG_TODO_OK;

	J3D_DEBUG_OK("Display created");
}

Display::~Display()
{
	glutLeaveMainLoop();
}

////////////////////////////////////////
// CORE

void Display::loop()
{
	glutMainLoop();
}

void Display::reshape(int w, int h)
{
	util::cycle::advise_reshape(true);
	glViewport(0, 0, w, h);
	engine::config()->window_width = w;
	engine::config()->window_height = h;
	J3D_BATCH(ReshapeBatch, reshape, w, h);
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

} }
