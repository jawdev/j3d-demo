/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/base/layer_base.h
*******************************************************************************/
#ifndef __J3D_LAYER_BASE__
#define __J3D_LAYER_BASE__
namespace j3d { namespace base {

/*******************************************************************************
* LAYERBASE
*******************************************************************************/

class LayerBase : public core::Group {
public:
	LayerBase(bool control_delete = true);
	virtual ~LayerBase();

	virtual void preRender();
	virtual void render();
	virtual void postRender();

	LayerBase *renderBuffer(RenderbufferBase *);
	const RenderbufferBase *renderBuffer() const;

private:
	RenderbufferBase *mp_render_buffer;

};

} }
#endif
