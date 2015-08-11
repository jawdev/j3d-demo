/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/batch.h
*******************************************************************************/
#ifndef __J3D_CORE_BATCH__
#define __J3D_CORE_BATCH__
namespace j3d { namespace core {

/*******************************************************************************
* BATCH
*******************************************************************************/

class Batch {
public:
	Batch(string id);
	virtual ~Batch();

private:
	string m_batch_id;

};

} }
#endif
