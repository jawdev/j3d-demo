/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /settings.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

bool Settings::debug					= true;

int Settings::window_width				= 800;
int Settings::window_height				= 600;
char* Settings::window_title			= "J3D";

unsigned int Settings::glut_cursor		= GLUT_CURSOR_NONE;
float Settings::mouse_buffer_time		= 0.01f;
bool Settings::mouse_warp				= false;

float Settings::render_distance_near	= 1;
float Settings::render_distance_far		= 1000;

}
