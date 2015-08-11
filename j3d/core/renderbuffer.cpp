/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/renderbuffer.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* RENDERBUFFER
*******************************************************************************/

Renderbuffer::Renderbuffer()
{
	m_width = engine::config()->window_width;
	m_height = engine::config()->window_height;
	//mp_renderbuffers = new GLuint[NUM_BUFFERS];
	init();
}

Renderbuffer::~Renderbuffer()
{
	//J3D_SAFE_DELETE_ARR(mp_renderbuffers);
}

void Renderbuffer::reshape(int w, int h)
{
	m_width = engine::config()->window_width;
	m_height = engine::config()->window_height;
	//glDeleteRenderbuffers(NUM_BUFFERS, mp_renderbuffers);
	//glDeleteFramebuffers(1, &m_framebuffer);
	init();
}

void Renderbuffer::init()
{
/*
	glGenRenderbuffers(NUM_BUFFERS, mp_renderbuffers);
	glBindRenderbuffer(GL_RENDERBUFFER, mp_renderbuffers[COLOR_BUFFER]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, m_width, m_height);
	glBindRenderbuffer(GL_RENDERBUFFER, mp_renderbuffers[DEPTH_BUFFER]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, m_width,
			m_height);
	
	glGenFramebuffers(1, &m_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
			GL_RENDERBUFFER, mp_renderbuffers[COLOR_BUFFER]);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
			GL_RENDERBUFFER, mp_renderbuffers[DEPTH_BUFFER]);
*/
}

void Renderbuffer::bind()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	//glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Renderbuffer::blit()
{
/*
	glBindFramebuffer(GL_READ_FRAMEBUFFER, m_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	glBlitFramebuffer(0, 0, m_width - 1, m_height - 1, 0, 0, m_width - 1,
			m_height - 1, GL_COLOR_BUFFER_BIT, GL_LINEAR);
*/
}

} }
