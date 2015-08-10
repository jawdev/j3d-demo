/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* demo.cpp
*******************************************************************************/
#include "inc.h"

/*******************************************************************************
* DEMO
*******************************************************************************/

Demo::Demo() : Scene("demo") {}
Demo::~Demo() {}

void Demo::load()
{
	mp_shader = new ShaderProgram();
	mp_shader->addVertexShader("assets/shaders/basic.vs");
	mp_shader->addFragmentShader("assets/shaders/basic.fs");
	mp_shader->link({"m4_camera", "m4_model", "v4_color"});

	new BoxMesh("box1");
	
}

void Demo::unload()
{
	delete mp_shader;
}


////////////////////////////////////////
// UPDATE

void Demo::update()
{

}
