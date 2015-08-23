/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/base/renderbuffer_base.h
*******************************************************************************/
#ifndef __J3D_BASE_RENDERBUFFER_BASE_H__
#define __J3D_BASE_RENDERBUFFER_BASE_H__
namespace j3d { namespace base {

class RenderbufferBase : public core::ReshapeBatch {
public:
	RenderbufferBase() {}
	virtual ~RenderbufferBase() {}

	virtual void reshape(int x, int y) {}
	virtual void bind() = 0;
	virtual void blit() = 0;

};

} }
#endif
