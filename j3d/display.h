/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/display.h
*******************************************************************************/
#ifndef __J3D_DISPLAY_H__
#define __J3D_DISPLAY_H__
namespace j3d {

/*******************************************************************************
* DISPLAY
*******************************************************************************/

class Display {
public:
	Display();
	virtual ~Display();

	virtual void loop();
	virtual void reshape(int w, int h);
	virtual void display();

	static void on_reshape(int w, int h);
	static void on_display();

};

}
#endif
