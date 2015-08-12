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

enum class camera_mode_t {
	DEFAULT
};

enum class camera_proj_t {
	PERSPECTIVE,
	NONE
};

class Camera : public core::Entity, public core::ReshapeBatch {
public:
	Camera(camera_mode_t = camera_mode_t::DEFAULT,
			camera_proj_t = camera_proj_t::PERSPECTIVE,
			float near = 0,
			float far = 0);
	virtual ~Camera();

	virtual void reshape();
	virtual void reshape(int x, int y) { reshape(); }
	virtual mat4 &transform();

	virtual Camera *mode(camera_mode_t);
	virtual Camera *proj(camera_proj_t);
	virtual Camera *near(const float &);
	virtual Camera *far(const float &);

	virtual camera_mode_t mode() const;
	virtual camera_proj_t proj() const;
	virtual float near() const;
	virtual float far() const;

protected:
	camera_mode_t o_mode;
	camera_proj_t o_proj;
	mat4 o_mat_proj;
	float o_near;
	float o_far;

};

}
#endif
