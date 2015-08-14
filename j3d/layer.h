/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/layer.h
*******************************************************************************/
#ifndef __J3D_LAYER__
#define __J3D_LAYER__
namespace j3d {

/*******************************************************************************
* LAYER
*******************************************************************************/

class Layer : public core::LayerBase {
public:
	Layer(bool control_delete = true);
	~Layer();

	Layer *add(Object *);
	Layer *add(initializer_list<Object *>);

	void render();
	void updateRender();

};

}
#endif
