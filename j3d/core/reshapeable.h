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

class Reshapeable : public Cacheable {
public:
	static const char constexpr *J3D_CACHE_ID = "reshapers";

public:
	Reshapeable();
	virtual ~Reshapeable();

	virtual void reshape(int x, int y);
	static void reshape_all(int x, int y);

};

} }
#endif
