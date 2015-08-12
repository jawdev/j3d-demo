/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/control_batch.h
*******************************************************************************/
#ifndef __J3D_CORE_CONTROL_BATCH__
#define __J3D_CORE_CONTROL_BATCH__
namespace j3d { namespace core {

/*******************************************************************************
* CONTROLBATCH
*******************************************************************************/

class ControlBatch : public Batch {
public:
	static const char constexpr *J3D_BATCH_ID = "j3d_control";

public:
	ControlBatch() : Batch(J3D_BATCH_ID) {}
	virtual ~ControlBatch() {}

	virtual void onKeyDown(unsigned char key) {}
	virtual void onKeyDown(unsigned char key, int x, int y) { onKeyDown(key); }
	virtual void onKeyUp(unsigned char key) {}
	virtual void onKeyUp(unsigned char key, int x, int y) { onKeyUp(key); }
	virtual void onSpecialDown(int key) {}
	virtual void onSpecialDown(int key, int x, int y) { onSpecialDown(key); }
	virtual void onSpecialUp(int key) {}
	virtual void onSpecialUp(int key, int x, int y) { onSpecialUp(key); }
	virtual void onMouseDown(int button) {}
	virtual void onMouseDown(int button, int x, int y) { onMouseDown(button); }
	virtual void onMouseUp(int button) {}
	virtual void onMouseUp(int button, int x, int y) { onMouseUp(button); }
	virtual void onMouseMove(int x, int y, int old_x, int old_y) {}

};


} }
#endif
