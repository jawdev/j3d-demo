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
	cache(const char *id1, const char *id2, bool activate = true);
	virtual ~cache();

	void activate();

public:
	static bool cache_group_exists(const char *);
	static void cache_group_create(const char *);
	static void cache_group_destroy(const char *, bool destroy = true);
	static void cache_group_destroy_all(bool destroy = true);

	static bool cache_exists(const char *id1);
	static bool cache_has(const char *, const char *);
	static bool cache_add(const char *, const char *, cache *);
	static cache *cache_get(const char *, const char *);
	static cache *cache_active(const char *);
	static void cache_activate(const char *id1, const char *id2);
	static bool cache_remove(const char *, const char *, bool destroy = false);
	static bool cache_dne_fatal(const char *, const char *);

private:
	static unordered_map<const char *,
			unordered_map<const char *, cache *>> m_caches;
	static unordered_map<const char *, cache *> m_active;
	static bool m_destroy_all;

	char *m_id1;
	char *m_id2;

};

} }

#define J3D_CACHE_EXISTS(obj)\
	j3d::util::cache::cache_exists(obj::CACHE_ID)

#define J3D_CACHE_ACTIVE(obj)\
	((obj *)j3d::util::cache::cache_active(obj::CACHE_ID))

#define J3D_CACHE_GET(obj, id2)\
	((obj *)j3d::util::cache::cache_get(obj::CACHE_ID, id2))

#endif
