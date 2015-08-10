/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/flaggable.h
*******************************************************************************/
#ifndef __J3D_UTIL_FLAGGABLE_H__
#define __J3D_UTIL_FLAGGABLE_H__
namespace j3d { namespace core {

/*******************************************************************************
* FLAGGABLE
*******************************************************************************/

class Flaggable {
public:
	Flaggable(uint64_t start_flags = 0x0);
	~Flaggable();

	void flag(uint64_t f);
	void unflag(uint64_t f);
	void noflags();

	bool flagged(uint64_t f);
	bool unflagged(uint64_t f);

	uint64_t flags();
	
protected:
	uint64_t o_flags;

};

} }
#endif
