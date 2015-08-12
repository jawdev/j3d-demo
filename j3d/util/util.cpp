/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/helpers.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

double now()
{
	return chrono::duration_cast<chrono::duration<double>>
			(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

string ptr2str(void *ptr)
{
	stringstream ss;
	ss << ptr;
	return ss.str();
}

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

bool fps::enabled = false;
unsigned int fps::latest = 0;
float fps::stopwatch = 0;
float fps::lap = 1;
unsigned int fps::counter = 0;
bool fps::notify = false;

void fps::tick(float delta)
{
	if (!enabled)
		return;
	notify = false;
	++counter;
	stopwatch += delta;
	if (stopwatch < lap)
		return;
	latest = counter / stopwatch;
	stopwatch = 0;
	counter = 0;
	notify = true;
}

}}
