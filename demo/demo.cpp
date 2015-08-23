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
	m_timer = 0;
	m_dir[0] = 0; m_dir[1] = 0;
	m_rot[0] = M_PI; m_rot[1] = 0;
}

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
	mp_cam->pos(vec3(-10, 0, 0));
	mp_cam->lookAt(vec3());
	mp_l1->add(mp_cam);

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
	Light *p_light = new Light(light_t::DIRECTIONAL);
	p_light->diffuse(vec3(1, 1, 1));
	p_light->ambient(vec3(0.3f, 0.3f, 0.3f));
	p_light->dir(vec3(0.5f, -1, -0.2f));
	p_light->assignDiffuseUniform("v3_light_col");
	p_light->assignAmbientUniform("v3_ambient");
	p_light->assignDirUniform("v3_light_dir");
	mp_l1->add(p_light);
	
	/*
	 * meshes
	 */
	new BoxMesh("cube");

	vec3 vmin(1, 1, 1);
	vec3 vmax(3, 3, 3);
	ray3 r(vec3(-1, 2, 2), vec3(1, 0, 0));
	if (rmath::intersection(r, vmin, vmax))
		cout << "HIT" << endl;
	else
		cout << "FAIL" << endl;

	/*
	 * objects
	 */
	mp_cube = new Cube();
	mp_l1->add(mp_cube);

/*
	int scale = 100;
	int range = scale * scale;
	float scale_f = (float)scale;
	int x, z;
	Cube *p_cube = new Cube();
	for (int i = 0; i < range; ++i) {
		x = i % scale;
		z = i / scale;
		p_cube = new Cube();
		p_cube->pos(vec3(x - scale_f / 2, 0, z - scale_f / 2));
		p_cube->lock();
		mp_l1->add(p_cube);
	}
*/
}

void Demo::unload()
{
	util::fps::disable();
	delete mp_l1;
}

////////////////////////////////////////
// CONTROL

void Demo::onKeyDown(unsigned char k)
{
	switch (k) {
	case 27:
		util::cycle::advise_quit(true);
		break;
	case 'w':
		m_dir[1] += 1;
		break;
	case 's':
		m_dir[1] -= 1;
		break;
	case 'a':
		m_dir[0] -= 1;
		break;
	case 'd':
		m_dir[0] += 1;
		break;
	default:
		break;
	}
}

void Demo::onKeyUp(unsigned char k)
{
	switch (k) {
	case 'w':
		m_dir[1] -= 1;
		break;
	case 's':
		m_dir[1] += 1;
		break;
	case 'a':
		m_dir[0] += 1;
		break;
	case 'd':
		m_dir[0] -= 1;
		break;
	default:
		break;
	}
}

void Demo::onMouseUp(int b, int x, int y)
{
	if (b != 0)
		return;
	ray3 r;
	rmath::screen_ray(&r, x, y);
	cout << r << endl;
	vec3 vmin, vmax;
	mp_cube->aabb(&vmin, &vmax);
	if (rmath::intersection(r, vmin, vmax))
		cout << "HIT!" << endl;
}

////////////////////////////////////////
// UPDATE

void Demo::update()
{
/*
	static float r = 4.0f;
	m_rot[0] -= (float)m_dir[0] * util::cycle::delta();
	m_rot[1] += (float)m_dir[1] * util::cycle::delta();
	mp_cam->pos(vec3(r * cos(m_rot[0]), r * sin(m_rot[1]), r * sin(m_rot[0])));
	mp_cam->lookAt(vec3());
*/
	
	mp_l1->updateRender();
	if (util::fps::notify())
		cout << "FPS = " << util::fps::latest() << "    " << '\r' << flush;
}
