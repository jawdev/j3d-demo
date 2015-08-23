/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/camera.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* CAMERA
*******************************************************************************/

Camera::Camera(string id) :
		base::CameraBase(id) {}
Camera::~Camera() {}

mat4 &Camera::projection()
{
	float a = (float)engine::config()->window_width;
	a /= (float)engine::config()->window_height;
	matrix::perspective(&o_mat_projection, -a, a, -1, 1, o_near, o_far);
	return o_mat_projection;
}

}
