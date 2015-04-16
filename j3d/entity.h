/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /entity.h
******************************************************************************/
#ifndef J3D_ENTITY_H_
#define J3D_ENTITY_H_
namespace j3d {

class Entity {
public:

	//====================================
	// INIT
	//====================================

	Entity();
	virtual ~Entity();

	//====================================
	// ATTRIBUTES
	//====================================

	Entity* position( vec3 );
	Entity* rotation( vec3 );
	Entity* velocity( vec3 );
	Entity* spin( vec3 );

	vec3 position();
	vec3 rotation();
	vec3 velocity();
	vec3 spin();

private:
	
	vec3 m_position;
	vec3 m_rotation;
	vec3 m_velocity;
	vec3 m_spin;

};

}
#endif
