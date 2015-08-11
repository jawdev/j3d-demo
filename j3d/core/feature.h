/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/feature.h
*******************************************************************************/
#ifndef __J3D_CORE_FEATURE_H__
#define __J3D_CORE_FEATURE_H__
namespace j3d { namespace core {

/*******************************************************************************
* FEATURE
*******************************************************************************/

class Feature {
	friend class Group;
public:
	Feature() {}
	virtual ~Feature() {}

	virtual void update() {}
	virtual void render() {}

	Group *group() const { return mp_group; }

private:
	Group *mp_group;

};

} }
#endif
