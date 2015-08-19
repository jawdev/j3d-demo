/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/group.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* GROUP
*******************************************************************************/

Group::Group(bool control_delete)
{
	m_control_delete = control_delete;
	mp_shader_program = nullptr;
	o_pre_render = false;
}

Group::~Group()
{
	if (m_control_delete)
		groupDelete();
	else
		o_features.clear();
}

//////////////////////////////////////////////////
// MAIN

Group *Group::groupAdd(Feature *f)
{
	o_features[util::ptr2str(f)] = f;
	f->mp_group = this;
	onGroupAdd(f);
	return this;
}

Group *Group::groupAdd(initializer_list<Feature *> fs)
{
	for (Feature *f : fs)
		add(f);
	return this;
}

Group *Group::groupRemove(Feature *f)
{
	onGroupRemove(f);
	if (m_control_delete)
		J3D_SAFE_DELETE(f);
	else
		f->mp_group = nullptr;
	o_features.erase(util::ptr2str(f));
	return this;
}

Group *Group::groupRemove(initializer_list<Feature *> fs)
{
	for (Feature *f : fs)
		remove(f);
	return this;
}

//////////////////////////////////////////////////
// UPDATE

void Group::groupUpdate()
{
	for (auto it = o_features.begin(); it != o_features.end(); ++it)
		((Feature *)it->second)->update();
}

void Group::groupPreRender()
{
	if (mp_shader_program != nullptr)
		mp_shader_program->use();
	o_pre_render = true;
}

void Group::groupRender()
{
	if (!o_pre_render)
		preRender();
	for (auto it = o_features.begin(); it != o_features.end(); ++it)
		((Feature *)it->second)->render();
	postRender();
	o_pre_render = false;
}

void Group::groupPostRender()
{
	o_pre_render = false;
}

void Group::groupUpdateRender()
{
	if (!o_pre_render)
		preRender();
	for (auto it = o_features.begin(); it != o_features.end(); ++it) {
		((Feature *)it->second)->update();
		((Feature *)it->second)->render();
	}
	postRender();
}

void Group::groupDelete()
{
	Feature *f;
	for (auto it = o_features.begin(); it != o_features.end(); ++it) {
		f = (Feature *)it->second;
		J3D_SAFE_DELETE(f);
	}
	o_features.clear();
}

//////////////////////////////////////////////////
// GET SET

Group *Group::groupControlDelete(bool b) { m_control_delete = b; return this; }

Group *Group::groupShaderProgram(const char *id)
{
	if (J3D_CACHE3(exists, ShaderProgram, id, true))
		mp_shader_program = J3D_CACHE_GET(ShaderProgram, id);
	return this;
}

Group *Group::groupShaderProgram(ShaderProgram *p)
{
	mp_shader_program = p;
	return this;
}

bool Group::groupControlDelete() const { return m_control_delete; }
ShaderProgram *Group::groupShaderProgram() const { return mp_shader_program; }

} }
