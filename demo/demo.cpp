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

Demo::Demo() : Scene("demo")
{
	m_time_agg = 0;
	m_counter = 0;
}

Demo::~Demo() {}

void Demo::load()
{

	/*
	 * 3D
	 */

	mp_l1 = new Layer();

	mp_shader = new ShaderProgram("basic");
	mp_shader->addFragmentShader("assets/shaders/basic.fs");
	mp_shader->addVertexShader("assets/shaders/basic.vs");
	mp_shader->link({"m4_camera", "m4_model", "v4_color"});
	mp_l1->shaderProgram(mp_shader);
	
	new BoxMesh("cube");

	mp_cube = new Cube("cube");
	mp_cube->rvel(vec3(0, 0.5f, 0));
	mp_l1->add(mp_cube);

	mp_cam = new Camera();
	mp_cam->pos(vec3(2, 1, 3));
	mp_cam->lookAt(vec3());
	mp_cam->lock();

	/*
	 * 2D
	 */

	mp_l2 = new Layer2D();

	new RectMesh("rect1", 1, 1, 0.1f, 0.1f);

	mp_layer = new Layer();
	mp_sprite = new Sprite("rect1");
	mp_l2->add(mp_sprite);

}

void Demo::unload()
{
	delete mp_l1;
	delete mp_l2;
}


////////////////////////////////////////
// UPDATE

void Demo::update()
{

	mp_l1->preRender();
	mp_shader->bind("m4_camera", mp_cam->transform());
	mp_l1->updateRender();

	++m_counter;
	m_time_agg += util::cycle::delta();
	if (m_time_agg >= 1) {
		cout << "FPS = " << (int)(m_counter / m_time_agg) <<
				"     " << '\r' << flush;
		m_counter = 0;
		m_time_agg = 0;
	}
}
