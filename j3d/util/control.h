/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/control.h
*******************************************************************************/
#ifndef __J3D_CONTROL_H__
#define __J3D_CONTROL_H__
namespace j3d { namespace util {

/*******************************************************************************
* CONTROL
*******************************************************************************/

class control {
public:
	static void init();
	static void update();

	static void on_key_down(unsigned char k, int x, int y);
	static void on_key_up(unsigned char k, int x, int y);
	static void on_special_down(int k, int x, int y);
	static void on_special_up(int k, int x, int y);
	static void on_mouse_click(int b, int s, int x, int y);
	static void on_mouse_move(int x, int y);
	
	static bool key_down(unsigned char);
	static bool special_down(int);
	static bool keys_down(initializer_list<unsigned char>);
	static bool specials_down(initializer_list<int>);
	static bool combo(initializer_list<int>, initializer_list<unsigned char>);

private:
	static const int K = 300;
	static const int S = 150;
	static const int M = 10;

	static bool m_init_complete;

	static bool m_key_down[K];
	static bool m_mouse_down[M];

	static bool m_recording;
	static float m_record_time;
	static int m_last_x;
	static int m_last_y;
	static int m_new_x;
	static int m_new_y;

};

} }
#endif
