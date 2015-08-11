/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/sprite.h
*******************************************************************************/
#ifndef __J3D_SPRITE_H__
#define __J3D_SPRITE_H__
namespace j3d {

/*******************************************************************************
* SPRITE
*******************************************************************************/

class Sprite : public core::Entity2D {
public:
	Sprite(const char *mesh_id);
	virtual ~Sprite();

	virtual void update();
	virtual void render();

private:
	Mesh2D *mp_mesh;

};

}
#endif
