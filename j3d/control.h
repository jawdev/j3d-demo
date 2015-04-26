/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /control.h
******************************************************************************/
#ifndef J3D_CONTROL_H_
#define J3D_CONRTOL_H_
namespace j3d {

///////////////////////////////////////////////// Control

class Control {
public:

	static void init();

	//====================================
	// CALLBACK
	//====================================

	static void callbackKeyDown( unsigned char key, int x, int y );
	static void callbackKeyUp( unsigned char key, int x, int y );
	static void callbackSpecialDown( int key, int x, int y );
	static void callbackSpecialUp( int key, int x, int y );

	static void callbackMouseClick( int button, int state, int x, int y );
	static void callbackMouseMove( int x, int y );

	static void update( float dtime );

	//====================================
	// TEST
	//====================================

	static bool keyDown( unsigned char );
	static bool specialDown( int key );
	static bool keysDown( initializer_list<unsigned char> );
	static bool specialsDown( initializer_list<int> );
	static bool combo( initializer_list<int>, initializer_list<unsigned char> );

private:

	static const unsigned int K = 300;
	static const unsigned int S = 150;
	static const unsigned int M = 10;
	static bool m_key_down[K];
	static bool m_mouse_down[M];
	static bool m_init_complete;

	static bool m_recording;
	static float m_record_time;
	static int m_last_x;
	static int m_last_y;
	static int m_new_x;
	static int m_new_y;

};

}
#endif
