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
	Object(const char *mesh_id);
	virtual ~Object();

	virtual void update();
	virtual void render();

protected:
	Mesh *op_mesh;
	
};

}
#endif
