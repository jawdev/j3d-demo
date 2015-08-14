/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/cycle.h
*******************************************************************************/
#ifndef __J3D_UTIL_CYCLE_H__
#define __J3D_UTIL_CYCLE_H__
namespace j3d { namespace util {

/*******************************************************************************
* CYCLE
*******************************************************************************/

class cycle {
	friend class j3d::engine;
public:

	static float delta();
	static double deltad();
	template<class T> static T delta();

	static bool advise_reshape();
	static bool advise_quit();

	static void advise_reshape(bool);
	static void advise_quit(bool);

private:
	static void tick();
	static void flush();
	
private:
	static double m_last_time;
	static double m_new_time;
	static double m_delta;
	static bool m_advise_reshape;
	static bool m_advise_quit;
	
};

} }
#endif
