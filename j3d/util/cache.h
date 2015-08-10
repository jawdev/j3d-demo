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

class cache {
public:
	static bool group_exists(string);
	static void group_create(string);
	static void group_destroy(string, bool destroy = true);
	static void group_destroy_all(bool destroy = true);

	static bool exists(string id1);
	static bool has(string, string);
	static bool add(string, string, void *);
	static void *get(string, string);
	static bool has_active(string);
	static void *active(string);
	static void activate(string id1, string id2);
	static bool remove(string, string, bool destroy = false);
	static bool dne_fatal(string, string);

	static void print();
	static void print(string);

private:
	static unordered_map<string, unordered_map<string, void *>> m_caches;
	static unordered_map<string, void *> m_active;
	static bool m_destroy_all;

};

/*******************************************************************************
* CACHEABLE
*******************************************************************************/

class Cacheable {
public:
	Cacheable(string id1, string id2, bool activate = true);
	virtual ~Cacheable();
	virtual void cacheActivate();

	const char *cacheId();
	const char *cacheIdFull();

private:
	string m_id1;
	string m_id2;

};

} }

#define J3D_CACHE_EXISTS(obj)\
	j3d::util::cache::exists(obj::J3D_CACHE_ID)

#define J3D_CACHE_HAS_ACTIVE(obj)\
	j3d::util::cache::has_active(obj::J3D_CACHE_ID)

#define J3D_CACHE_HAS(obj, id)\
	j3d::util::cache::has(obj::J3D_CACHE_ID, id)

#define J3D_CACHE_ACTIVE(obj)\
	((obj *)j3d::util::cache::active(obj::J3D_CACHE_ID))

#define J3D_CACHE_GET(obj, id2)\
	((obj *)j3d::util::cache::get(obj::J3D_CACHE_ID, id2))

#define J3D_CACHE_DESTROY_GROUP(obj)\
	j3d::util::cache::group_destroy(obj::J3D_CACHE_ID)

#endif
