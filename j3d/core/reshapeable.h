/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/reshapeable.h
*******************************************************************************/
#ifndef __J3D_CORE_RESHAPEABLE__
#define __J3D_CORE_RESHAPEABLE__
namespace j3d { namespace core {

/*******************************************************************************
* RESHAPEABLE
*******************************************************************************/

class Reshapeable : public Batch {
public:
	static const char constexpr *J3D_BATCH_ID = "reshapeable";

public:
	Reshapeable();
	virtual ~Reshapeable();
	virtual void reshape(int x, int y);

};

} }
#endif
