/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/camera_base.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* CAMERABASE
*******************************************************************************/

CameraBase::CameraBase(string id, bool ac) :
		Cacheable(J3D_CACHE_ID, id, false)
{
	o_mat_projection.iden();
	o_near = engine::config()->render_distance_near;
	o_far = engine::config()->render_distance_far;
	if (ac)
		activate();
}

CameraBase::~CameraBase() {}

void CameraBase::activate()
{
	J3D_DEBUG_TODO("activating Camera: " << cacheIdFull());
	cacheActivate();
	J3D_DEBUG_TODO_OK;
}

////////////////////////////////////////
// UPDATE

void CameraBase::reshape(int w, int h)
{
	projection();
}

mat4 &CameraBase::transform()
{
	if (o_locked && o_calcd_transform)
		return o_mat_transform;
	vmath::translation(&o_mat_pos, -o_pos);
	vmath::rotation(&o_mat_rot, -o_rot);
	o_mat_transform = o_mat_rot * o_mat_pos;
	o_mat_transform = o_mat_projection * o_mat_transform;
	o_calcd_transform = true;
	return o_mat_transform;
}

void CameraBase::render()
{
	runBindings();
}

////////////////////////////////////////
// SET GET

CameraBase *CameraBase::near(float f) { o_near = f; return this; }
CameraBase *CameraBase::far(float f) { o_far = f; return this; }

float CameraBase::near() const { return o_near; }
float CameraBase::far() const { return o_far; }

} }
