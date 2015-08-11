/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* demo/cube.cpp
*******************************************************************************/
#include "inc.h"

/*******************************************************************************
* CUBE
*******************************************************************************/

Cube::Cube(const char *mesh_id) : Object(mesh_id)
{
}

Cube::~Cube() {}

void Cube::render()
{
	transform();
	group()->shaderProgram()->bind("m4_model", transform());
	Object::render();
}
