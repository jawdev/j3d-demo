/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/cycle.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

/*******************************************************************************
* CYCLE
*******************************************************************************/

double cycle::m_last_time = 0;
double cycle::m_new_time = 0;
double cycle::m_delta = 0;
bool cycle::m_advise_reshape = true;


float cycle::delta()
{
	return (float)m_delta;
}

double cycle::deltad()
{
	return m_delta;
}

template<class T> T cycle::delta()
{
	return (T)m_delta;
}

bool cycle::advise_reshape() { return m_advise_reshape; }
void cycle::advise_reshape(bool b) { m_advise_reshape = b; }

////////////////////////////////////////
// ENGINE

void cycle::tick()
{
	m_new_time = util::now();
	m_delta = m_new_time - m_last_time;
}

void cycle::flush()
{
	m_last_time = m_new_time;
	m_advise_reshape = false;
}

} }
