/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /renderbuffer.h
******************************************************************************/
#ifndef J3D_RENDERBUFFER_H_
#define J3D_RENDERBUFFER_H_
namespace j3d {

class Renderbuffer {
public:

	static const unsigned int COLOR_BUFFER	= 0;
	static const unsigned int DEPTH_BUFFER	= 1;
	static const unsigned int NUM_BUFFERS	= 2;

public:

	//====================================
	// MAIN
	//====================================

	Renderbuffer();
	~Renderbuffer();

	//====================================
	// BIND
	//====================================

	void reshape( unsigned int w, unsigned int h );
	void bind();
	void blit( unsigned int fid = 0 );

	//====================================
	// GET
	//====================================

	unsigned int with();
	unsigned int height();
	GLuint glFramebuffer();
	GLuint glRenderbuffer( unsigned int id );

private:

	unsigned int m_width;
	unsigned int m_height;
	GLuint m_framebuffer;
	GLuint* mp_renderbuffers;

};

}
#endif
