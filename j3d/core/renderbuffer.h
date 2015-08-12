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

class Renderbuffer : public RenderbufferBase {
public:
	static const int	NUM_BUFFERS		= 2;
	static const int	COLOR_BUFFER	= 0;
	static const int	DEPTH_BUFFER 	= 1;

public:
	Renderbuffer();
	~Renderbuffer();

private:
	void init();

public:
	void reshape(int x, int y);
	void bind();
	void blit();


private:
	int m_width;
	int m_height;
	GLuint m_framebuffer;
	GLuint *mp_renderbuffers;
};

} }
#endif
