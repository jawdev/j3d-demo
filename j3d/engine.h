/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/engine.h
*******************************************************************************/
#ifndef __J3D_ENGINE_H__
#define __J3D_ENGINE_H__
namespace j3d {

/*******************************************************************************
* ENGINE
*******************************************************************************/

class engine {
public:
	static void init(const Config &);
	static void quit(int exit_code = 0);
	static void run();

	static void atexit_callback();
	static void sigint_handler(int);
	static void update();

	static bool initialized();
	static Config *config();
	static core::Display *display();

private:
	static bool m_init_complete;
	static Config m_config;
	static core::Display *mp_display;
	
};

}
#endif
