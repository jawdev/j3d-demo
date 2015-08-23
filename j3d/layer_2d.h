/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/layer_2d.h
*******************************************************************************/
#ifndef __J3D_LAYER_2D__
#define __J3D_LAYER_2D__
namespace j3d {

/*******************************************************************************
* LAYER
*******************************************************************************/

class Layer2D : public base::LayerBase {
public:
	Layer2D(bool control_delete = true);
	~Layer2D();

	Layer2D *add(Sprite *);
	Layer2D *add(initializer_list<Sprite *>);
};

}
#endif

