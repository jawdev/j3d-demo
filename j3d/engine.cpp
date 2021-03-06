/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/engine.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* ENGINE
*******************************************************************************/

bool engine::m_init_complete = false;
Config engine::m_config;
base::Display *engine::mp_display = nullptr;

////////////////////////////////////////
// INIT

void engine::init(const Config &s)
{
	J3D_DEBUG_PUSH("engine init");
	if (m_init_complete) {
		J3D_DEBUG_WARN("already initialized");
		return;
	}
	m_init_complete = true;

	J3D_DEBUG_TODO("loading Config");
	m_config = s;
	J3D_DEBUG_TODO_OK;

	if (m_config.register_atexit) {
		J3D_DEBUG_TODO("registering atexit callback");
		atexit(j3d::engine::atexit_callback);
		J3D_DEBUG_TODO_OK;
	}
	if (m_config.register_sigint) {
		J3D_DEBUG_TODO("registering sigint handler");
		struct sigaction a;
		a.sa_handler = j3d::engine::sigint_handler;
		sigemptyset(&a.sa_mask);
		a.sa_flags = 0;
		sigaction(SIGINT, &a, NULL);
		J3D_DEBUG_TODO_OK;
	}

	J3D_DEBUG_PUSH("Display init");
	mp_display = new base::Display();
	J3D_DEBUG_POP;

	J3D_DEBUG_PUSH("control init");
	util::control::init();
	J3D_DEBUG_POP;

	J3D_DEBUG_OK("engine initialized");
	J3D_DEBUG_POP;
}

void engine::quit(int exit_code)
{
	J3D_DEBUG_PUSH("engine quit");
	if (!m_init_complete) {
		J3D_DEBUG_WARN("already quit");
		return;
	}
	m_init_complete = false;

	if (J3D_CACHE(active_exists, Scene)) {
		J3D_DEBUG_TODO("unloading active Scene");
		J3D_CACHE_ACTIVE(Scene)->unload();
		J3D_DEBUG_TODO_OK;
	}

	J3D_DEBUG_TODO("deleting Display");
	delete mp_display;
	J3D_DEBUG_TODO_OK;

	J3D_DEBUG_PUSH("cache clear");
	util::cache::clear();
	J3D_DEBUG_POP;

	J3D_DEBUG_TODO("clearing batches");
	util::batches::clear();
	J3D_DEBUG_TODO_OK;

	if (m_config.register_sigint) {
		J3D_DEBUG_TODO("releasing sigint handler");
		signal(SIGINT, SIG_DFL);
		J3D_DEBUG_TODO_OK;
	}

	J3D_DEBUG_OK("engine terminated");
	if (exit_code > 0) {
		J3D_DEBUG_ERROR("exiting with code " << exit_code);
		exit(exit_code);
	}
	J3D_DEBUG_POP;
}

void engine::run()
{
	if (!J3D_CACHE(active_exists, Scene))
		J3D_DEBUG_FATAL("please create a Scene");
	J3D_CACHE_ACTIVE(Scene)->activate();
	util::cycle::tick();
	util::cycle::flush();
	mp_display->loop();
}

////////////////////////////////////////
// CORE

void engine::atexit_callback()
{
	if (m_init_complete)
		quit();
}

void engine::sigint_handler(int code)
{
	cout << endl;
	if (m_init_complete)
		quit();
	exit(0);
}

void engine::update()
{
	if (util::cycle::advise_quit()) {
		mp_display->leaveLoop();
		quit();
		return;
	}
	util::cycle::tick();
	J3D_CACHE_ACTIVE(Scene)->update();
	util::cycle::flush();
}

////////////////////////////////////////
// GET SET

bool engine::initialized() { return m_init_complete; }
Config *engine::config() { return &m_config; }
base::Display *engine::display() { return mp_display; }

}
