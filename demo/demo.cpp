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

	util::fps::enabled = true;

	/*
	 * 3D
	 */

	mp_l1 = new Layer();

	mp_cam = new Camera("primary");
	mp_cam->pos(vec3(0, 0, 4));
	mp_cam->vel(vec3(0, 0.2f, 0));
	mp_cam->lookAt(vec3());

	mp_shader = new ShaderProgram("basic");
	mp_shader->addFragmentShader("assets/shaders/basic.fs");
	mp_shader->addVertexShader("assets/shaders/basic.vs");
	mp_shader->link({"m4_camera", "m4_model", "v4_color"});
	mp_shader->assignBinding("m4_camera", &mp_cam->transform());
	mp_l1->shaderProgram(mp_shader);
	
	new BoxMesh("cube");

	mp_cube = new Cube("cube");
	mp_cube->pos(vec3(-1, -1, 0));
	mp_cube->rvel(vec3(0, 0.2f, 0));
	mp_l1->add(mp_cube);

	mp_cube2 = new Cube("cube");
	mp_cube2->pos(vec3(1, 1, 0));
	mp_cube2->rvel(vec3(0, -0.2f, 0));
	mp_l1->add(mp_cube2);

/*
 * SCREEN RAYS
	mp_cam->transform();
	cout << mp_cam->pos() << endl;
	vec4 v(1, 1, -1, 1);
	cout << v << endl;
	vec4 v2 = v * vmath::invert(mp_cam->transform());
	cout << v2 << endl;
	cout << vmath::norm(v2 - mp_cam->pos()) << endl;
*/
	
}

void Demo::unload()
{
	util::fps::enabled = false;
	delete mp_cam;
	delete mp_l1;
}


////////////////////////////////////////
// UPDATE

void Demo::update()
{
	mp_l1->updateRender();

	if (util::fps::notify)
		cout << "FPS = " << util::fps::latest << "    " << '\r' << flush;
}
