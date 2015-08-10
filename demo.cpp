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
	glClearColor(1, 0, 0, 1);

	mp_shader = new ShaderProgram();
	mp_shader->addVertexShader("assets/shaders/basic.vs");
	mp_shader->addFragmentShader("assets/shaders/basic.fs");
	mp_shader->link({"m4_camera", "m4_model", "v4_color"});
	
	new BoxMesh("box1");
	new FloorMesh("floor1", 10, 10);

	mp_box = new Object("box1");
	mp_box->pos(vec3(0, 1, 0));
	mp_box->rvel(vec3(0, 0.1f, 0));

	mp_floor = new Object("floor1");
	mp_floor->lock();

	mp_cam = new Camera();
	mp_cam->pos(vec3(2, 2, 3));
	mp_cam->lookAt(vec3());
	mp_cam->lock();
}

void Demo::unload()
{
	delete mp_box;
	delete mp_floor;
	delete mp_cam;
	delete mp_shader;
}


////////////////////////////////////////
// UPDATE

void Demo::update()
{
	if (util::cycle::advise_reshape())
		mp_cam->reshape();

/*
	mp_shader->bind("m4_model", mp_floor->transform());
	mp_shader->bind("v4_color", vec4(1, 1, 1, 1));
	mp_floor->render();
*/

	mp_shader->bind("m4_model", mp_box->transform());
	mp_shader->bind("v4_color", vec4(1, 1, 1, 1));
	mp_box->render();

	mp_shader->bind("m4_camera", mp_cam->transform());

	++m_counter;
	m_time_agg += util::cycle::delta();
	if (m_time_agg >= 1) {
		cout << "FPS = " << (int)(m_counter / m_time_agg) <<
				"     " << '\r' << flush;
		m_counter = 0;
		m_time_agg = 0;
	}
}
