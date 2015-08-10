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

unordered_map<string, unordered_map<string, core::Cacheable *>> cache::m_caches;
unordered_map<string, core::Cacheable *> cache::m_active;
bool cache::m_destroy_all = false;

unordered_map<string, core::Cacheable *> &cache::group(string id)
{
	return m_caches.at(id);
}

size_t cache::group_size(string id)
{
	if (!group_exists(id))
		return 0;
	return m_caches.at(id).size();
}

string cache::group_next_id(string id)
{
	stringstream ss;
	ss << group_size(id);
	return ss.str();
}

bool cache::group_exists(string id)
{
	try {
		m_caches.at(id);
	} catch (...) {
		return false;
	}
	return true;
}

void cache::group_create(string id)
{
	m_caches[id] = unordered_map<string , core::Cacheable *>();
	m_active[id] = nullptr;
}

void cache::group_destroy(string id, bool destroy)
{
	if (!destroy) {
		m_active.erase(id);
		m_caches[id].clear();
		return;
	}
	for (auto iter = m_caches[id].begin(); iter != m_caches[id].end(); ++iter)
		delete (core::Cacheable *)iter->second;
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
			delete (core::Cacheable *)jter->second;
		}
		iter->second.clear();
	}
	m_caches.clear();
	m_active.clear();
	m_destroy_all = false;
}

bool cache::exists(string id1)
{
	if (!group_exists(id1))
		return false;
	try {
		return !m_caches[id1].empty();
	} catch (...) {
		J3D_DEBUG_ERROR("cache group could not be found: [" << id1 << "]");
		return false;
	}
}

bool cache::has(string id1, string id2)
{
	try {
		m_caches.at(id1).at(id2);
	} catch (...) {
		return false;
	}
	return true;
}

bool cache::add(string id1, string id2, core::Cacheable *el)
{
	try {
		m_caches[id1][id2] = el;
	} catch (...) {
		J3D_DEBUG_ERROR("cache group could not be found: [" << id1 << "]");
		return false;
	}
	return true;
}

core::Cacheable *cache::get(string id1, string id2)
{
	try {
		return m_caches[id1][id2];
	} catch (...) {
		J3D_DEBUG_ERROR("cache item could not be found: [" << id1 << "]["
				<< id2 << "]");
		return nullptr;
	}
}

core::Cacheable *cache::active(string id1)
{
	try {
		return m_active[id1];
	} catch (...) {
		J3D_DEBUG_ERROR("cache active item could not be found: [" << id1 << "]");
		return nullptr;
	}
}

bool cache::has_active(string id1)
{
	return (group_exists(id1) && m_active[id1] != nullptr);
}

void cache::activate(string id1, string id2)
{
	m_active[id1] = m_caches[id1][id2];
}

bool cache::remove(string id1, string id2, bool destroy)
{
	if (m_destroy_all)
		return true;
	core::Cacheable *c;
	try {
		c = m_caches[id1][id2];
	} catch (...) {
		J3D_DEBUG_ERROR("cache item could not be found: [" << id1 << "]["
				<< id2 << "]");
		return false;
	}
	m_caches[id1].erase(id2);
	if (m_active[id1] == c) {
		if (m_caches[id1].empty())
			m_active[id1] = nullptr;
		else
			m_active[id1] = m_caches[id1].begin()->second;
	}
	if (destroy)
		delete (core::Cacheable *)c;
	return true;
}

bool cache::dne_fatal(string id1, string id2)
{
	if (has(id1, id2)) {
		J3D_DEBUG_FATAL("cached item already exists: [" << id1 << "][" << id2
				<< "]");
		return false;
	}
	return true;
}

void cache::print()
{
	for (auto iter = m_caches.begin(); iter != m_caches.end(); ++iter)
		print(iter->first);
}

void cache::print(string id1)
{
	cout << id1 << " {\n";
	for (auto iter = m_caches[id1].begin(); iter != m_caches[id1].end(); ++iter)
		cout << "\t" << iter->first << " -> " << iter->second << "\n";
	cout << "}" << endl;
}

} }
