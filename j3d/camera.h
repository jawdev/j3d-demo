/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /camera.h
******************************************************************************/
#ifndef J3D_CAMERA_H_
#define J3D_CAMERA_H_
namespace j3d {

enum class camera_mode_t {
	DEFAULT	= 0
};

class Camera : public Entity {
public:
	
	//====================================
	// INIT
	//====================================

	Camera( camera_mode_t = camera_mode_t::DEFAULT );
	~Camera();

private:
	camera_mode_t m_mode;

};

}
#endif
