/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/renderbuffer_2d.h
*******************************************************************************/
#ifndef __J3D_CORE_RENDERBUFFER_2D_H__
#define __J3D_CORE_RENDERBUFFER_2D_H__
namespace j3d { namespace core {

/*******************************************************************************
* RENDERBUFFER2D
*******************************************************************************/

class Renderbuffer2D : public RenderbufferBase {
public:
	Renderbuffer2D();
	~Renderbuffer2D();

	void reshape(int x, int y);
	void bind();
	void blit();

private:
	int m_width;
	int m_height;
	GLuint m_framebuffer;
	GLuint m_renderbuffer;

};

} }
#endif
