/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/scene.h
*******************************************************************************/
#ifndef __J3D_SCENE_H__
#define __J3D_SCENE_H__
namespace j3d {

class Scene : public core::Cacheable, public core::ControlBatch {
	friend class engine;
public:
	static const char constexpr *J3D_CACHE_ID = "scene";

public:
	Scene(const char *id, bool activate = true);
	virtual ~Scene();

	void cacheActivate();
	void activate();

protected:
	virtual void load() {}
	virtual void unload() {}
	virtual void update() {}

private:

};

}
#endif
