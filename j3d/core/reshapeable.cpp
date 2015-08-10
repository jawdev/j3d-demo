/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/reshapeable.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* RESHAPEABLE
*******************************************************************************/

Reshapeable::Reshapeable()
		: Cacheable(J3D_CACHE_ID, util::cache::group_next_id(J3D_CACHE_ID)) {}

Reshapeable::~Reshapeable() {}

void Reshapeable::reshape(int x, int y) {}

void Reshapeable::reshape_all(int x, int y)
{
	if (!util::cache::group_exists(J3D_CACHE_ID))
		return;
	auto l = util::cache::group(J3D_CACHE_ID);
	for (auto it = l.begin(); it != l.end(); ++it) {
		((Reshapeable *)it->second)->reshape(x, y);
	}
}

} }
