/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/cache.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

/*******************************************************************************
* CACHE
*******************************************************************************/

unordered_map<const char *,
		unordered_map<const char *, void *>> cache::m_caches;
unordered_map<const char *, void *> cache::m_active;
bool cache::m_destroy_all = false;


////////////////////////////////////////
// STATICS

bool cache::group_exists(const char *id)
{
	try {
		m_caches.at(id);
	} catch (...) {
		return false;
	}
	return true;
}

void cache::group_create(const char *id)
{
	m_caches[id] = unordered_map<const char *, void *>();
	m_active[id] = nullptr;
}

void cache::group_destroy(const char *id, bool destroy)
{
	if (!destroy) {
		m_active.erase(id);
		m_caches[id].clear();
		return;
	}
	for (auto iter = m_caches[id].begin(); iter != m_caches[id].end(); ++iter)
		delete (Cacheable *)iter->second;
	m_caches[id].clear();
	m_active.erase(id);
	m_caches.erase(id);
}

void cache::group_destroy_all(bool destroy)
{
	m_destroy_all = true;
	for (auto iter = m_caches.begin(); iter != m_caches.end(); ++iter) {
		J3D_DEBUG_TODO("clearing cache group: [" << iter->first << "]");
		if (!destroy) {
			iter->second.clear();
			continue;
		}
		for (auto jter = iter->second.begin(); jter != iter->second.end();
				++jter) {
			delete (Cacheable *)jter->second;
		}
		iter->second.clear();
	}
	m_caches.clear();
	m_active.clear();
	m_destroy_all = false;
}

bool cache::exists(const char *id1)
{
	if (!group_exists(id1))
		return false;
	try {
		return (m_caches[id1].size() > 0);
	} catch (...) {
		J3D_DEBUG_ERROR("cache group could not be found: [" << id1 << "]");
		return false;
	}
}

bool cache::has(const char *id1, const char *id2)
{
	try {
		m_caches.at(id1).at(id2);
	} catch (...) {
		return false;
	}
	return true;
}

bool cache::add(const char *id1, const char *id2, void *el)
{
	try {
		m_caches[id1][id2] = el;
	} catch (...) {
		J3D_DEBUG_ERROR("cache group could not be found: [" << id1 << "]");
		return false;
	}
	return true;
}

void *cache::get(const char *id1, const char *id2)
{
	try {
		return m_caches[id1][id2];
	} catch (...) {
		J3D_DEBUG_ERROR("cache item could not be found: [" << id1 << "]["
				<< id2 << "]");
		return nullptr;
	}
}

void *cache::active(const char *id1)
{
	try {
		return m_active[id1];
	} catch (...) {
		J3D_DEBUG_ERROR("cache active item could not be found: [" << id1 << "]");
		return nullptr;
	}
}

void cache::activate(const char *id1, const char *id2)
{
	m_active[id1] = m_caches[id1][id2];
}

bool cache::remove(const char *id1, const char *id2, bool destroy)
{
	if (m_destroy_all)
		return true;
	void *c;
	try {
		c = m_caches[id1][id2];
	} catch (...) {
		J3D_DEBUG_ERROR("cache item could not be found: [" << id1 << "]["
				<< id2 << "]");
		return false;
	}
	m_caches[id1].erase(id2);
	if (m_active[id1] == c) {
		if (m_caches.size() == 0)
			m_active[id1] = nullptr;
		else
			m_active[id1] = m_caches[id1].end()->second;
	}
	if (destroy)
		delete (Cacheable *)c;
	return true;
}

bool cache::dne_fatal(const char *id1, const char *id2)
{
	if (has(id1, id2)) {
		J3D_DEBUG_FATAL("cached item already exists: [" << id1 << "][" << id2
				<< "]");
		return false;
	}
	return true;
}

/*******************************************************************************
* CACHEABLE
*******************************************************************************/

Cacheable::Cacheable(const char *id1, const char *id2, bool activate)
{
	m_id1 = new char[strlen(id1) + 1];
	strcpy(m_id1, id1);
	m_id2 = new char[strlen(id2) + 1];
	strcpy(m_id2, id2);
	if (!cache::group_exists(m_id1))
		cache::group_create(m_id1);
	cache::dne_fatal(m_id1, m_id2);
	cache::add(m_id1, m_id2, this);
	if (activate)
		cacheActivate();
}

Cacheable::~Cacheable()
{
	cache::remove(m_id1, m_id2);
	delete [] m_id1;
	delete [] m_id2;
}

void Cacheable::cacheActivate()
{
	cache::activate(m_id1, m_id2);
}

} }
