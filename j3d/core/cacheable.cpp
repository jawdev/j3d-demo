/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/cacheable.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* CACHEABLE
*******************************************************************************/

Cacheable::Cacheable(string id1, string id2, bool activate)
{
	m_id1 = id1;
	m_id2 = id2;
	if (!util::cache::group_exists(m_id1))
		util::cache::group_create(m_id1);
	util::cache::dne_fatal(m_id1, m_id2);
	util::cache::add(m_id1, m_id2, this);
	if (activate)
		cacheActivate();
}

Cacheable::~Cacheable()
{
	util::cache::remove(m_id1, m_id2, false);
}

void Cacheable::cacheActivate()
{
	util::cache::activate(m_id1, m_id2);
}

const char *Cacheable::cacheId()
{
	return m_id2.c_str();
}

const char *Cacheable::cacheIdFull()
{
	stringstream ss;
	ss << m_id1 << "." << m_id2 << " -> " << (void *)this;
	return ss.str().c_str();
}

} }
