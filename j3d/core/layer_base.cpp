/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/layer_base.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* LAYERBASE
*******************************************************************************/

LayerBase::LayerBase(bool del)
		: Group(del)
{
	mp_render_buffer = nullptr;
}

LayerBase::~LayerBase()
{
	J3D_SAFE_DELETE(mp_render_buffer);
}

////////////////////////////////////////
// UPDATE

void LayerBase::preRender()
{
	if (mp_render_buffer != nullptr)
		mp_render_buffer->bind();
	Group::preRender();
}

void LayerBase::render()
{
	Group::render();
}

void LayerBase::postRender()
{
	if (mp_render_buffer != nullptr)
		mp_render_buffer->blit();
	Group::postRender();
}

////////////////////////////////////////
// SET GET

LayerBase *LayerBase::renderBuffer(RenderbufferBase *r)
{
	mp_render_buffer = r;
	return this;
}

const RenderbufferBase *LayerBase::renderBuffer() const
{
	return mp_render_buffer;
}

} }
