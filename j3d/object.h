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

class Object : public base::Entity {
public:
	Object(const string &mesh_id);
	Object(const string &mesh_id, const string &shader_id);
	virtual ~Object();

private:
	void init(const string &mesh_id);

public:
	virtual void update();
	virtual void render();

private:
	Mesh *mp_mesh;
	
};

}
#endif
