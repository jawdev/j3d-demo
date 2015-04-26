/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /object.h
******************************************************************************/
#ifndef J3D_OBJECT_H_
#define J3D_OBJECT_H_
namespace j3d {

///////////////////////////////////////////////// Object

class Object : public Entity {
public:

	Object( char* mesh_name, vec4 color = vec4( 1, 1, 1, 1 ) );
	~Object();

	//====================================
	// UPDATE
	//====================================

	void update( float dtime );
	void render();

	//====================================
	// ATTRIBUTES
	//====================================

	Object* color( vec4 );

	vec4 color();

private:
	Mesh* mp_mesh;
	vec4 m_color;

};

}
#endif
