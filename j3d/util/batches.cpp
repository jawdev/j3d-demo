/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/batches.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

/*******************************************************************************
* BATCHES
*******************************************************************************/

batchmap batches::m_batches;

void batches::clear()
{
	m_batches.clear();
}

void batches::add(string id, batchobj *ptr)
{
	batchgroup *g;
	try {
		g = &m_batches.at(id);
	} catch (...) {
		m_batches[id] = batchgroup();
		g = &m_batches.at(id);
	}
	g->push_back(ptr);
}

void batches::remove(string id, batchobj *ptr)
{
	batchgroup *g;
	try {
		g = &m_batches.at(id);
	} catch (...) {
		J3D_DEBUG_ERROR("batch does not exist: " << id);
		return;
	}
	for (size_t i = 0; i < g->size(); ++i)
		if (g->at(i) == ptr) {
			g->erase(g->begin() + i);
			return;
		}
}

batchgroup *batches::get(string id)
{
	batchgroup *g = nullptr;
	try {
		g = &m_batches.at(id);
	} catch (...) {
		return nullptr;
	}
	return g;
}

} }
