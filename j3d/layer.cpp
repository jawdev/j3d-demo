/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/layer.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* LAYER
*******************************************************************************/

Layer::Layer(bool del) : LayerBase(del)
{
	LayerBase::renderBuffer(new base::Renderbuffer());
}

Layer::~Layer() {}

////////////////////////////////////////
// UPDATE

void Layer::render()
{
	if (!o_pre_render)
		preRender();
	if (J3D_CACHE(active_exists, base::CameraBase))
		J3D_CACHE_ACTIVE(base::CameraBase)->render();
	Object *obj;
	for (auto it = o_features.begin(); it != o_features.end(); ++it) {
		obj = (Object *)it->second;
		obj->bindUniforms();
		obj->render();
	}
	postRender();
}

void Layer::updateRender()
{
	if (!o_pre_render)
		preRender();
	if (J3D_CACHE(active_exists, base::CameraBase)) {
		J3D_CACHE_ACTIVE(base::CameraBase)->update();
		J3D_CACHE_ACTIVE(base::CameraBase)->render();
	}
	Object *obj;
	for (auto it = o_features.begin(); it != o_features.end(); ++it) {
		obj = (Object *)it->second;
		obj->update();
		obj->bindUniforms();
		obj->render();
	}
	postRender();
}

void Layer::onGroupAdd(core::Feature *f)
{
	base::Entity *e = (base::Entity *)f;
	if (e->shaderProgram() == nullptr)
		e->shaderProgram(groupShaderProgram());
}

}
