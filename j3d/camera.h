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

enum class camera_proj_t {
	NONE = 0,
	PERSPECTIVE
};

class Camera : public Entity {
public:
	
	//====================================
	// INIT
	//====================================

	Camera( camera_mode_t = camera_mode_t::DEFAULT, camera_proj_t = camera_proj_t::PERSPECTIVE, float = 0, float = 0 );
	~Camera();

	//====================================
	// UPDATE
	//====================================

	void reshape();
	void update( float dtime );

	mat4 transform();

private:
	camera_mode_t m_mode;
	camera_proj_t m_proj;
	mat4 m_mat_proj;
	float m_near;
	float m_far;

};

}
#endif
