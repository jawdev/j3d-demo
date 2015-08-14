/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/camera.h
*******************************************************************************/
#ifndef __J3D_CAMERA_H__
#define __J3D_CAMERA_H__
namespace j3d {

/*******************************************************************************
* CAMERA
*******************************************************************************/

class Camera : public core::CameraBase {
public:
	Camera(string id);
	virtual ~Camera();
	virtual mat4 &projection();

};

}
#endif
