/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /display.h
******************************************************************************/
#ifndef J3D_DISPLAY_H_
#define J3D_DISPLAY_H_
namespace j3d {

class Display {
public:

	//====================================
	// MAIN
	//====================================

	Display();
	~Display();
	void mainLoop();

	//====================================
	// CALLBACKS
	//====================================

	static void callbackReshape( int w, int h );
	static void callbackDisplay();
	static void callbackQuit();

	//====================================
	// RENDER BUFFERS
	//====================================

	Renderbuffer* renderbuffer();

private:
	Renderbuffer* mp_renderbuffer;
};

}
#endif
