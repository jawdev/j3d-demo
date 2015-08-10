/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/renderbuffer.h
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* RENDERBUFFER
*******************************************************************************/

Renderbuffer::Renderbuffer(const char *id) : util::Cacheable(J3D_CACHE_ID, id)
{
	o_width = engine::config()->window_width;
	o_height = engine::config()->window_height;
	op_renderbuffers = new GLuint[NUM_BUFFERS];
	glGenRenderbuffers(NUM_BUFFERS, op_renderbuffers);

	glBindRenderbuffer(GL_RENDERBUFFER, op_renderbuffers[COLOR_BUFFER]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, o_width, o_height);

	glBindRenderbuffer(GL_RENDERBUFFER, op_renderbuffers[DEPTH_BUFFER]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, o_width,
			o_height);
	
	glGenFramebuffers(1, &o_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, o_framebuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
			GL_RENDERBUFFER, op_renderbuffers[COLOR_BUFFER]);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
			GL_RENDERBUFFER, op_renderbuffers[DEPTH_BUFFER]);
	
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
}

Renderbuffer::~Renderbuffer()
{
	delete [] op_renderbuffers;
}

void Renderbuffer::reshape(int w, int h)
{
	o_width = engine::config()->window_width;
	o_height = engine::config()->window_height;
	glDeleteRenderbuffers(NUM_BUFFERS, op_renderbuffers);
	glGenRenderbuffers(NUM_BUFFERS, op_renderbuffers);

	glBindRenderbuffer(GL_RENDERBUFFER, op_renderbuffers[COLOR_BUFFER]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, o_width, o_height);

	glBindRenderbuffer(GL_RENDERBUFFER, op_renderbuffers[DEPTH_BUFFER]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, o_width,
			o_height);
	
	glGenFramebuffers(1, &o_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, o_framebuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
			GL_RENDERBUFFER, op_renderbuffers[COLOR_BUFFER]);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
			GL_RENDERBUFFER, op_renderbuffers[DEPTH_BUFFER]);

}

void Renderbuffer::bind(unsigned int fid)
{
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, o_framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fid);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Renderbuffer::blit()
{
	glBlitFramebuffer(0, 0, o_width - 1, o_height - 1, 0, 0, o_width - 1,
			o_height - 1, GL_COLOR_BUFFER_BIT, GL_NEAREST);
}

} }
