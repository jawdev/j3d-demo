/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/control.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

/*******************************************************************************
* CONTROL
*******************************************************************************/

bool control::m_init_complete = false;
bool control::m_key_down[control::K] = {0};
bool control::m_mouse_down[control::M] = {0};
bool control::m_recording = false;
float control::m_record_time = 0;
int control::m_last_x = 0;
int control::m_last_y = 0;
int control::m_new_x = 0;
int control::m_new_y = 0;

void control::init()
{
	if (m_init_complete) {
		J3D_DEBUG_WARN("already initialized");
		return;
	}
	m_init_complete = true;

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(on_key_down);
	glutKeyboardUpFunc(on_key_up);
	glutSpecialFunc(on_special_down);
	glutSpecialUpFunc(on_special_up);
	glutMouseFunc(on_mouse_click);
	glutPassiveMotionFunc(on_mouse_move);
}

void control::update()
{
	if (!m_recording)
		return;
	m_record_time += cycle::delta();
	if (m_record_time < engine::config()->mouse_buffer_time)
		return;
	m_record_time = 0;
	if (J3D_CACHE_HAS_ACTIVE(Scene))
		J3D_CACHE_ACTIVE(Scene)->onMouseMove(m_new_x, m_new_y,
				m_last_x, m_last_y);
	m_last_x = m_new_x;
	m_last_y = m_new_y;
	m_recording = false;
}

////////////////////////////////////////
// EVENT CALLBACKS

void control::on_key_down(unsigned char k, int x, int y)
{
	m_key_down[(int)k] = true;
	if (J3D_CACHE_HAS_ACTIVE(Scene))
		J3D_CACHE_ACTIVE(Scene)->onKeyDown(k, x, y);
}

void control::on_key_up(unsigned char k, int x, int y)
{
	m_key_down[(int)k] = false;
	if (J3D_CACHE_HAS_ACTIVE(Scene))
		J3D_CACHE_ACTIVE(Scene)->onKeyUp(k, x, y);
}

void control::on_special_down(int k, int x, int y)
{
	m_key_down[k + S] = true;
	if (J3D_CACHE_HAS_ACTIVE(Scene))
		J3D_CACHE_ACTIVE(Scene)->onSpecialDown(k, x, y);
}

void control::on_special_up(int k, int x, int y)
{
	m_key_down[k + S] = false;
	if (J3D_CACHE_HAS_ACTIVE(Scene))
		J3D_CACHE_ACTIVE(Scene)->onSpecialUp(k, x, y);
}

void control::on_mouse_click(int b, int s, int x, int y)
{
	switch (s) {
	case GLUT_DOWN:
		m_mouse_down[b] = true;
		if (J3D_CACHE_HAS_ACTIVE(Scene))
			J3D_CACHE_ACTIVE(Scene)->onMouseDown(b, x, y);
		break;
	case GLUT_UP:
		m_mouse_down[b] = false;
		if (J3D_CACHE_HAS_ACTIVE(Scene))
			J3D_CACHE_ACTIVE(Scene)->onMouseUp(b, x, y);
		break;
	default:
		J3D_DEBUG_WARN("unrecognized mouse state {state = " << s <<
				", button = " << b << "}");
		break;
	}
}

void control::on_mouse_move(int x, int y)
{
	m_recording = true;
	m_new_x = x;
	m_new_y = y;
}

////////////////////////////////////////
// GET

bool control::key_down(unsigned char k) { return m_key_down[(int)k]; }
bool control::special_down(int k) { return m_key_down[k + S]; }

bool control::keys_down(initializer_list<unsigned char> keys)
{
	for (unsigned char k : keys)
		if (!key_down(k))
			return false;
	return true;
}

bool control::specials_down(initializer_list<int> keys)
{
	for (int k : keys)
		if (!special_down(k))
			return false;
	return true;
}

bool control::combo(initializer_list<int> s, initializer_list<unsigned char> k)
{
	return (specials_down(s) && keys_down(k));
}

} }
