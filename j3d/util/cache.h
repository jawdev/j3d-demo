/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/cache.h
*******************************************************************************/
#ifndef __J3D_UTIL_CACHE__
#define __J3D_UTIL_CACHE__
namespace j3d { namespace util {

/*******************************************************************************
* CACHE
*******************************************************************************/

typedef core::Cacheable cacheitem;
typedef unordered_map<string, cacheitem *> cachegroup;
typedef unordered_map<string, cachegroup> cachemap;

class cache {
public:
	static void clear(bool call_delete = true);
	static void print();
	static void print(string id1);

	static bool	group_create(string id1);
	static bool group_destroy(string id1, bool call_delete = true);
	static const cachegroup *group_get(string);
	static bool group_exists(string id1, bool debug_error = false);
	static bool group_empty(string id1);
	static size_t group_size(string id1);

	static bool add(string id1, string id2, cacheitem *, bool mkgrp = false);
	static bool remove(string id1, string id2, bool call_delete = false);
	static cacheitem *get(string id1, string id2);
	static bool exists(string id1, string id2, bool debug_error = false);
	static bool activate(string id1, string id2);
	static cacheitem *active_get(string id1);
	static bool active_exists(string id1);

private:
	static cachemap m_caches;
	static cachegroup m_actives;
	static bool m_clearing;

};

} }

////////////////////////////////////////
// TOKEN DEFINES

#define J3D_CACHE(_func, _obj)\
	j3d::util::cache::_func(_obj::J3D_CACHE_ID)

#define J3D_CACHE2(_func, _obj, _p2)\
	j3d::util::cache::_func(_obj::J3D_CACHE_ID, _p2)

#define J3D_CACHE3(_func, _obj, _p2, _p3)\
	j3d::util::cache::_func(_obj::J3D_CACHE_ID, _p2, _p3)

#define J3D_CACHE4(_func, _obj, _p2, _p3, _p4)\
	j3d::util::cache::_func(_obj::J3D_CACHE_ID, _p2, _p3, _p4)

////////////////////////////////////////
// SHORTCUTS

#define J3D_CACHE_ACTIVE(obj) ((obj *)J3D_CACHE(active_get, obj))
#define J3D_CACHE_GET(obj, id2) ((obj *)J3D_CACHE2(get, obj, id2))

#endif
