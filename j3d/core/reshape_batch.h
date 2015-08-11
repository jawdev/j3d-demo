/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/reshape_batch.h
*******************************************************************************/
#ifndef __J3D_CORE_RESHAPE_BATCH__
#define __J3D_CORE_RESHAPE_BATCH__
namespace j3d { namespace core {

/*******************************************************************************
* RESHAPEABLE
*******************************************************************************/

class ReshapeBatch : public Batch {
public:
	static const char constexpr *J3D_BATCH_ID = "reshapeable";

public:
	ReshapeBatch();
	virtual ~ReshapeBatch();
	virtual void reshape(int x, int y);

};

} }
#endif
