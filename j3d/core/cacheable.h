/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/cacheable.h
*******************************************************************************/
#ifndef __J3D_CORE_CACHEABLE__
#define __J3D_CORE_CACHEABLE__
namespace j3d { namespace core {

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
#endif
