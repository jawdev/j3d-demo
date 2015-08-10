/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/renderbuffer.h
*******************************************************************************/
#ifndef __J3D_CORE_RENDERBUFFER_H__
#define __J3D_CORE_RENDERBUFFER_H__
namespace j3d { namespace core {

/*******************************************************************************
* RENDERBUFFER
*******************************************************************************/

class Renderbuffer : public core::Reshapeable {
public:
	static const int			NUM_BUFFERS		= 2;
	static const int			COLOR_BUFFER	= 0;
	static const int			DEPTH_BUFFER 	= 1;

public:
	Renderbuffer();
	virtual ~Renderbuffer();
	
	virtual void reshape(int w, int h);
	virtual void bind(unsigned int fid = 0);
	virtual void blit();

protected:
	int o_width;
	int o_height;
	GLuint o_framebuffer;
	GLuint *op_renderbuffers;
};

} }
#endif
