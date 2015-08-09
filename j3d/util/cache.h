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
	static bool group_exists(const char *);
	static void group_create(const char *);
	static void group_destroy(const char *, bool destroy = true);
	static void group_destroy_all(bool destroy = true);

	static bool exists(const char *id1);
	static bool has(const char *, const char *);
	static bool add(const char *, const char *, void *);
	static void *get(const char *, const char *);
	static void *active(const char *);
	static void activate(const char *id1, const char *id2);
	static bool remove(const char *, const char *, bool destroy = false);
	static bool dne_fatal(const char *, const char *);

private:
	static unordered_map<const char *,
			unordered_map<const char *, void *>> m_caches;
	static unordered_map<const char *, void *> m_active;
	static bool m_destroy_all;

};

/*******************************************************************************
* CACHEABLE
*******************************************************************************/

class Cacheable {
public:
	Cacheable(const char *id1, const char *id2, bool activate = true);
	virtual ~Cacheable();
	void cacheActivate();

private:
	char *m_id1;
	char *m_id2;

};

} }

#define J3D_CACHE_EXISTS(obj)\
	j3d::util::cache::exists(obj::J3D_CACHE_ID)

#define J3D_CACHE_ACTIVE(obj)\
	((obj *)j3d::util::cache::active(obj::J3D_CACHE_ID))

#define J3D_CACHE_GET(obj, id2)\
	((obj *)j3d::util::cache::get(obj::J3D_CACHE_ID, id2))

#endif
