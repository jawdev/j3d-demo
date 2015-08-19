/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/helpers.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

/*******************************************************************************
* CHRONO
*******************************************************************************/

double now()
{
	return chrono::duration_cast<chrono::duration<double>>
			(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

/*******************************************************************************
* POINTERS
*******************************************************************************/

string ptr2str(void *ptr)
{
	stringstream ss;
	ss << ptr;
	return ss.str();
}

/*******************************************************************************
* FILES
*******************************************************************************/

char *file_get_contents(const char *filename, bool zero_term)
{
	ifstream in(filename, ios::in|ios::binary);
	if (!in)
		J3D_DEBUG_FATAL("file could not be found: " << filename);
	in.seekg(0, ios::end);
	unsigned int len = (unsigned int)in.tellg();
	char *contents = new char[len + 1];
	in.seekg(0, ios::beg);
	in.read(contents, len);
	in.close();
	if (zero_term)
		contents[len] = 0;
	return contents;
}

/*******************************************************************************
* FPS
*******************************************************************************/

bool fps::m_enabled = false;
unsigned int fps::m_latest = 0;
float fps::m_stopwatch = 0;
float fps::m_lap = 1;
unsigned int fps::m_counter = 0;
bool fps::m_notify = false;

////////////////////////////////////////
// SET GET

void fps::enable(bool b) { m_enabled = b; }
void fps::disable(bool b) { enable(!b); }
void fps::lap(float f) { m_lap = f; }

bool fps::enabled() { return m_enabled; }
unsigned int fps::latest() { return m_latest; }
float fps::lap() { return m_lap; }
bool fps::notify() { return m_notify; }

////////////////////////////////////////
// TICK

void fps::tick(float delta)
{
	if (!m_enabled)
		return;
	m_notify = false;
	++m_counter;
	m_stopwatch += delta;
	if (m_stopwatch < m_lap)
		return;
	m_latest = m_counter / m_stopwatch;
	m_stopwatch = 0;
	m_counter = 0;
	m_notify = true;
}

}}
