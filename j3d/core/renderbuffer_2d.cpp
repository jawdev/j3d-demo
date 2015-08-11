/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/renderbuffer_2d.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* RENDERBUFFER2D
*******************************************************************************/

Renderbuffer2D::Renderbuffer2D()
{
	m_width = engine::config()->window_width;
	m_height = engine::config()->window_height;

/*
	glGenRenderbuffers(1, &m_renderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, m_renderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, m_width, m_height);
	
	glGenFramebuffers(1, &m_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
			GL_RENDERBUFFER, m_renderbuffer);
*/
}

Renderbuffer2D::~Renderbuffer2D() {}

void Renderbuffer2D::reshape(int w, int h)
{
	m_width = engine::config()->window_width;
	m_height = engine::config()->window_height;

/*
	glDeleteRenderbuffers(1, &m_renderbuffer);
	glGenRenderbuffers(1, &m_renderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, m_renderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, m_width, m_height);
	
	glDeleteFramebuffers(1, &m_framebuffer);
	glGenFramebuffers(1, &m_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
			GL_RENDERBUFFER, m_renderbuffer);
*/
}

void Renderbuffer2D::bind()
{
/*
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);
	glClear(GL_COLOR_BUFFER_BIT);
*/
}

void Renderbuffer2D::blit()
{
/*
	glBindFramebuffer(GL_READ_FRAMEBUFFER, m_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	glBlitFramebuffer(0, 0, m_width - 1, m_height - 1, 0, 0, m_width - 1,
			m_height - 1, GL_COLOR_BUFFER_BIT, GL_LINEAR);
*/
}

} }
