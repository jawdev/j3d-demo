/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/camera_base.h
*******************************************************************************/
#ifndef __J3D_CORE_CAMERA_BASE__
#define __J3D_CORE_CAMERA_BASE__
namespace j3d { namespace core {

/*******************************************************************************
* CAMERABASE
*******************************************************************************/

class CameraBase : public Entity, public ReshapeBatch {
public:
	CameraBase();
	CameraBase(string uniform_id);
	virtual ~CameraBase();

private:
	void init();

public:
	virtual void reshape(int w = 0, int h = 0);
	virtual mat4 &projection() = 0;
	virtual mat4 &transform();
	virtual void render();

	CameraBase *near(float);
	CameraBase *far(float);

	virtual float near() const;
	virtual float far() const;
	
protected:
	mat4 o_mat_projection;
	float o_near;
	float o_far;
	string o_uniform_id;

};

} }
#endif