/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/object.h
*******************************************************************************/
#ifndef __J3D_OBJECT_H__
#define __J3D_OBJECT_H__
namespace j3d {

/*******************************************************************************
* OBJECT
*******************************************************************************/

class Object : public core::Entity {
public:
	Object(string mesh_id);
	Object(string mesh_id, string shader_id);
	virtual ~Object();

	virtual void update();
	virtual void render();

private:
	Mesh *mp_mesh;
	
};

}
#endif
