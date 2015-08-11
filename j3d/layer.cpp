/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/layer.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* LAYER
*******************************************************************************/

Layer::Layer(bool del) : LayerBase(del)
{
	LayerBase::renderBuffer(new core::Renderbuffer());
}

Layer::~Layer() {}

Layer *Layer::add(Object *o)
{
	Group::add(o);
	return this;
}

Layer *Layer::add(initializer_list<Object *> os)
{
	for (Object *o : os)
		add(o);
	return this;
}

}
