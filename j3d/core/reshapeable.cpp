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
		: Batch(J3D_BATCH_ID) {}

Reshapeable::~Reshapeable() {}

void Reshapeable::reshape(int x, int y) {}

} }
