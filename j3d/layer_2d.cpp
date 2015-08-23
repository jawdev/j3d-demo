/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/layer_2d.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* LAYER2D
*******************************************************************************/


Layer2D::Layer2D(bool del) : LayerBase(del)
{
	if (J3D_CACHE2(exists, ShaderProgram, "j3d_layer_2d"))
		groupShaderProgram("j3d_layer_2d");
	else {
		ShaderProgram *p = new ShaderProgram("j3d_layer_2d");
		p->addVertexShader("assets/shaders/layer.vs");
		p->addFragmentShader("assets/shaders/layer.fs");
		p->link({"v4_color"}, false);
		groupShaderProgram(p);
	}
	LayerBase::renderBuffer(new base::Renderbuffer2D());
}

Layer2D::~Layer2D() {}

Layer2D *Layer2D::add(Sprite *s)
{
	Group::add(s);
	return this;
}

Layer2D *Layer2D::add(initializer_list<Sprite *> ss)
{
	for (Sprite *s : ss)
		add(s);
	return this;
}

}
