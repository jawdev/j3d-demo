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
	util::fps::enable();

	/*
	 * layer
	 */
	mp_l1 = new Layer();

	/*
	 * camera
	 */
	mp_cam = new Camera("primary");
	mp_cam->pos(vec3(0, 0, 4));
	mp_cam->lookAt(vec3());

	/*
	 * shader program
	 */
	mp_shader = new ShaderProgram("basic");
	mp_shader->addFragmentShader("assets/shaders/basic.fs");
	mp_shader->addVertexShader("assets/shaders/basic.vs");
	mp_shader->link({"m4_camera", "m4_model", "v4_color", "v3_light_col",
			"v3_ambient", "v3_light_dir"});
	mp_shader->assignUniform("m4_camera", &mp_cam->transform());
	mp_l1->shaderProgram(mp_shader);

	/*
	 * lighting
	 */
	mp_light = new Light(light_t::DIRECTIONAL);
	mp_light->diffuse(vec3(1, 1, 1));
	mp_light->ambient(vec3(0.3f, 0.3f, 0.3f));
	mp_light->dir(vec3(0.5f, -1, -0.2f));
	mp_light->assignDiffuseUniform("v3_light_col");
	mp_light->assignAmbientUniform("v3_ambient");
	mp_light->assignDirUniform("v3_light_dir");
	mp_l1->add(mp_light);
	
	/*
	 * meshes
	 */
	new BoxMesh("cube");

	/*
	 * objects
	 */
	mp_cube = new Cube();
	mp_cube->pos(vec3(-1, -1, 0));
	mp_cube->rvel(vec3(0, 0.5f, 0));
	mp_l1->add(mp_cube);

	mp_cube2 = new Cube();
	mp_cube2->pos(vec3(1, 1, 0));
	mp_cube2->rvel(vec3(0, -0.5f, 0));
	mp_l1->add(mp_cube2);
}

void Demo::unload()
{
	util::fps::disable();
	delete mp_l1;
}


////////////////////////////////////////
// UPDATE

void Demo::update()
{
	mp_l1->updateRender();

	if (util::fps::notify())
		cout << "FPS = " << util::fps::latest() << "    " << '\r' << flush;
}

void Demo::onKeyDown(unsigned char k)
{
	if (k == 27)
		util::cycle::advise_quit(true);
}
