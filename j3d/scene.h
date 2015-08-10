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

class Scene : public core::Cacheable {
	friend class engine;
	friend class util::control;
public:
	static const char constexpr *J3D_CACHE_ID = "scene";

public:
	Scene(const char *id, bool activate = true)
			: core::Cacheable(J3D_CACHE_ID, id, activate) {}
	virtual ~Scene() {}

	void cacheActivate()
	{
		J3D_CACHE_DESTROY_GROUP(Mesh);
		J3D_CACHE_DESTROY_GROUP(ShaderProgram::Shader);
		if (J3D_CACHE_HAS_ACTIVE(Scene) &&
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

	virtual void onKeyDown(unsigned char key) {}
	virtual void onKeyDown(unsigned char key, int x, int y) { onKeyDown(key); }
	virtual void onKeyUp(unsigned char key) {}
	virtual void onKeyUp(unsigned char key, int x, int y) { onKeyUp(key); }
	virtual void onSpecialDown(int key) {}
	virtual void onSpecialDown(int key, int x, int y) { onSpecialDown(key); }
	virtual void onSpecialUp(int key) {}
	virtual void onSpecialUp(int key, int x, int y) { onSpecialUp(key); }
	virtual void onMouseDown(int button) {}
	virtual void onMouseDown(int button, int x, int y) { onMouseDown(button); }
	virtual void onMouseUp(int button) {}
	virtual void onMouseUp(int button, int x, int y) { onMouseUp(button); }
	virtual void onMouseMove(int x, int y, int old_x, int old_y) {}

private:

};

}
#endif
