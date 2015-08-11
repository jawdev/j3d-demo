/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/batch.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* BATCH
*******************************************************************************/

Batch::Batch(string id)
{
	m_batch_id = id;
	util::batches::add(id, this);
}

Batch::~Batch()
{
	util::batches::remove(m_batch_id, this);
}

} }
