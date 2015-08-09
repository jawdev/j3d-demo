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

class Renderbuffer : public util::cache {
public:
	static const char constexpr	*CACHE_ID		= "j3d_renderbuffer";
	static const int			NUM_BUFFERS		= 2;
	static const int			COLOR_BUFFER	= 0;
	static const int			DEPTH_BUFFER 	= 1;

public:
	Renderbuffer(const char *id);
	~Renderbuffer();
	
	void reshape(int w, int h);
	void bind(unsigned int fid = 0);
	void blit();

private:
	int m_width;
	int m_height;
	GLuint m_framebuffer;
	GLuint *mp_renderbuffers;
};

} }
#endif
