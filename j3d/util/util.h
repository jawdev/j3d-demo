/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/helpers.h
*******************************************************************************/
#ifndef __J3D_UTIL_HELPERS_H__
#define __J3D_UTIL_HELPERS_H__
namespace j3d { namespace util {

/*******************************************************************************
* CHRONO
*******************************************************************************/

double now();

/*******************************************************************************
* POINTERS
*******************************************************************************/

template<class T>
struct is_pointer { static const bool value = false; };
template<class T>
struct is_pointer<T *> { static const bool value = true; };

string ptr2str(void *);

/*******************************************************************************
* FILES
*******************************************************************************/

char *file_get_contents(const char *filename, bool zero_term = false);

/*******************************************************************************
* FPS
*******************************************************************************/

class fps {
	friend class cycle;
public:
	static void enable(bool b = true);
	static void disable(bool b = true);
	static void lap(float);

	static bool enabled();
	static unsigned int latest();
	static float lap();
	static bool notify();

private:
	static void tick(float delta);

private:
	static bool m_enabled;
	static unsigned int m_latest;
	static float m_stopwatch;
	static float m_lap;
	static unsigned int m_counter;
	static bool m_notify;
};

} }
#endif
