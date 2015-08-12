/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/scene.h
*******************************************************************************/
#ifndef __J3D_SCENE_H__
#define __J3D_SCENE_H__
namespace j3d {

class engine;

class Scene : public core::Cacheable, public core::ControlBatch {
	friend class engine;
public:
	static const char constexpr *J3D_CACHE_ID = "scene";

public:
	Scene(const char *id, bool activate = true) :
			core::Cacheable(J3D_CACHE_ID, id, activate),
			core::ControlBatch() {}
			
	virtual ~Scene() {}

	void cacheActivate()
	{
		J3D_CACHE(group_destroy, Mesh);
		J3D_CACHE(group_destroy, ShaderProgram::Shader);
		if (J3D_CACHE(active_exists, Scene) &&
					J3D_CACHE_ACTIVE(Scene) != this) {
			J3D_DEBUG_TODO("unloading Scene: " <<
					J3D_CACHE_ACTIVE(Scene)->cacheIdFull());
			J3D_CACHE_ACTIVE(Scene)->unload();
		}
		Cacheable::cacheActivate();
		J3D_DEBUG_TODO("loading Scene: " << cacheIdFull());
		load();
		J3D_DEBUG_OK("Scene loaded: " << cacheIdFull());
	}
	void activate() { cacheActivate(); }

protected:
	virtual void load() {}
	virtual void unload() {}
	virtual void update() {}

private:

};

}
#endif
