/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/scene.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

Scene::Scene(const char *id, bool activate) :
		core::Cacheable(J3D_CACHE_ID, id, activate),
		core::ControlBatch()
{}

Scene::~Scene() {}

void Scene::cacheActivate()
{
	J3D_DEBUG_PUSH("Scene activate: " << cacheIdFull());
	if (J3D_CACHE(group_exists, Mesh))
		J3D_CACHE(group_destroy, Mesh);
	if (J3D_CACHE(group_exists, ShaderProgram::Shader))
		J3D_CACHE(group_destroy, ShaderProgram::Shader);
	if (J3D_CACHE(group_exists, ShaderProgram))
		J3D_CACHE(group_destroy, ShaderProgram);
	if (J3D_CACHE(active_exists, Scene) &&
				J3D_CACHE_ACTIVE(Scene) != this) {
		J3D_DEBUG_PUSH("Scene unload: " <<
				J3D_CACHE_ACTIVE(Scene)->cacheIdFull());
		J3D_CACHE_ACTIVE(Scene)->unload();
		J3D_DEBUG_POP;
	}
	Cacheable::cacheActivate();
	J3D_DEBUG_PUSH("Scene load: " << cacheIdFull());
	load();
	J3D_DEBUG_OK("Scene loaded");
	J3D_DEBUG_POP;
	J3D_DEBUG_OK("Scene activated");
	J3D_DEBUG_POP;
}

void Scene::activate()
{
	cacheActivate();
}

}
