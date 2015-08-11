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

cachemap cache::m_caches;
cachegroup cache::m_actives;
bool cache::m_clearing = false;

////////////////////////////////////////
// MAIN

void cache::clear(bool del)
{
	m_clearing = true;
	for (auto it = m_caches.begin(); it != m_caches.end(); ++it)
		group_destroy(it->first, del);
	m_caches.clear();
	m_clearing = false;
}

void cache::print()
{
	for (auto it = m_caches.begin(); it != m_caches.end(); ++it)
		print(it->first);
}

void cache::print(string id1)
{
	cout << id1 << " {\n";
	for (auto it = m_caches[id1].begin(); it != m_caches[id1].end(); ++it)
		cout << "\t" << it->first << " -> " << it->second << "\n";
	cout << "}" << endl;
}

////////////////////////////////////////
// GROUP

bool cache::group_create(string id1)
{
	if (group_exists(id1)) {
		J3D_DEBUG_FATAL("group already exists: " << id1);
		return false;
	}
	m_caches[id1] = cachegroup();
	m_actives[id1] = nullptr;
	return true;
}

bool cache::group_destroy(string id1, bool del)
{
	if (!group_exists(id1, true))
		return false;
	J3D_DEBUG_TODO("clearing cache group: " << id1);
	if (del) {
		cacheitem *ptr;
		for (auto it = m_caches[id1].begin(); it != m_caches[id1].end(); ++it) {
			ptr = it->second;
			J3D_SAFE_DELETE(ptr);
		}
	}
	J3D_DEBUG_OK("cache group cleared: " << id1);
	m_actives.erase(id1);
	if (!m_clearing)
		m_caches.erase(id1);
	return true;
}

const cachegroup *cache::group_get(string id1) { return &m_caches.at(id1); }

bool cache::group_exists(string id1, bool dbg)
{
	try {
		m_caches.at(id1);
	} catch (...) {
		if (dbg)
			J3D_DEBUG_WARN("group does not exist: " << id1);
		return false;
	}
	return true;
}

bool cache::group_empty(string id1)
{
	if (!group_exists(id1, true))
		return true;
	return m_caches.at(id1).empty();
}

size_t cache::group_size(string id1)
{
	if (!group_exists(id1, true))
		return 0;
	return m_caches.at(id1).size();
}

////////////////////////////////////////
// ITEM

bool cache::add(string id1, string id2, cacheitem *ptr, bool mkgrp)
{
	if (!group_exists(id1, !mkgrp)) {
		if (!mkgrp)
			return false;
		group_create(id1);
	}
	if (exists(id1, id2)) {
		J3D_DEBUG_FATAL("item already exists: " << id1 << "." << id2);
		return false;
	}
	m_caches[id1][id2] = ptr;
	return true;
}

bool cache::remove(string id1, string id2, bool del)
{
	if (m_clearing)
		return true;
	if (!exists(id1, id2, true))
		return false;
	cacheitem *ptr = m_caches.at(id1).at(id2);
	if (m_actives[id1] == ptr)
		m_actives[id1] = m_caches[id1].begin()->second;
	if (del)
		J3D_SAFE_DELETE(ptr);
	m_caches[id1].erase(id2);
	if (m_caches[id1].empty())
		m_actives[id1] = nullptr;
	return true;
}

cacheitem *cache::get(string id1, string id2)
{
	return m_caches.at(id1).at(id2);
}

bool cache::exists(string id1, string id2, bool dbg)
{
	if (!group_exists(id1, dbg))
		return false;
	try {
		m_caches.at(id1).at(id2);
	} catch (...) {
		if (dbg)
			J3D_DEBUG_ERROR("item could not be found: " << id1 << "." << id2);
		return false;
	}
	return true;
}

bool cache::activate(string id1, string id2)
{
	if (!exists(id1, id2, true))
		return false;
	m_actives[id1] = m_caches[id1][id2];
	return true;
}

cacheitem *cache::active_get(string id1)
{
	return m_actives[id1];
}

bool cache::active_exists(string id1)
{
	if (!group_exists(id1, true))
		return false;
	if (m_caches[id1].empty() || m_actives[id1] == nullptr)
		return false;
	return true;
}

} }
