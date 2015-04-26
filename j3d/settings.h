/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /settings.h
******************************************************************************/
#ifndef J3D_SETTINGS_H_
#define J3D_SETTINGS_H_
namespace j3d {

class Settings {
public:

	static bool			debug;

	static int			window_width;
	static int			window_height;
	static char* 		window_title;

	static unsigned int	glut_cursor;
	static float		mouse_buffer_time;
	static bool			mouse_warp;

	static float		render_distance_near;
	static float		render_distance_far;

};

}
#endif
