/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* demo/cube.h
*******************************************************************************/
#ifndef __DEMO_CUBE_H__
#define __DEMO_CUBE_H__

/*******************************************************************************
* CUBE
*******************************************************************************/

class Cube : public Object {
public:
	Cube() : Object("cube", "basic")
	{
		assignUniform("m4_model", &o_mat_transform);
	}
	~Cube() {}

};

#endif
