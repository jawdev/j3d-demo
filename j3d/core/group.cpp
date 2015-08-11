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
	m_pre_render = false;
}

Group::~Group()
{
	if (m_control_delete)
		destroy();
	else
		m_features.clear();
}

//////////////////////////////////////////////////
// MAIN

Group *Group::add(Feature *f)
{
	m_features[util::ptr2str(f)] = f;
	f->mp_group = this;
	return this;
}

Group *Group::add(initializer_list<Feature *> fs)
{
	for (Feature *f : fs)
		add(f);
	return this;
}

Group *Group::remove(Feature *f)
{
	if (m_control_delete)
		J3D_SAFE_DELETE(f);
	else
		f->mp_group = nullptr;
	m_features.erase(util::ptr2str(f));
	return this;
}

Group *Group::remove(initializer_list<Feature *> fs)
{
	for (Feature *f : fs)
		remove(f);
	return this;
}

//////////////////////////////////////////////////
// UPDATE

void Group::update()
{
	for (auto it = m_features.begin(); it != m_features.end(); ++it)
		((Feature *)it->second)->update();
}

void Group::preRender()
{
	if (mp_shader_program != nullptr)
		mp_shader_program->use();
	m_pre_render = true;
}

void Group::render()
{
	if (!m_pre_render)
		preRender();
	for (auto it = m_features.begin(); it != m_features.end(); ++it)
		((Feature *)it->second)->render();
	postRender();
	m_pre_render = false;
}

void Group::postRender() {}

void Group::updateRender()
{
	if (!m_pre_render)
		preRender();
	for (auto it = m_features.begin(); it != m_features.end(); ++it) {
		((Feature *)it->second)->update();
		((Feature *)it->second)->render();
	}
	postRender();
	m_pre_render = false;
}

void Group::destroy()
{
	Feature *f;
	for (auto it = m_features.begin(); it != m_features.end(); ++it) {
		f = (Feature *)it->second;
		J3D_SAFE_DELETE(f);
	}
	m_features.clear();
}

//////////////////////////////////////////////////
// GET SET

Group *Group::controlDelete(bool b) { m_control_delete = b; return this; }

Group *Group::shaderProgram(const char *id)
{
	if (J3D_CACHE3(exists, ShaderProgram, id, true))
		mp_shader_program = J3D_CACHE_GET(ShaderProgram, id);
	return this;
}

Group *Group::shaderProgram(ShaderProgram *p)
{
	mp_shader_program = p;
	return this;
}

bool Group::controlDelete() const { return m_control_delete; }
ShaderProgram *Group::shaderProgram() const { return mp_shader_program; }

} }