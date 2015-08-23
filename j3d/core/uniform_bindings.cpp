/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/uniform_bindings.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* SHADERPROFILE
*******************************************************************************/

UniformBindings::UniformBindings(ShaderProgram *p)
{
	mp_shader_program = p;
	m_enabled = true;
}

UniformBindings::UniformBindings(string id)
{
	if (!J3D_CACHE2(exists, ShaderProgram, id))
		J3D_DEBUG_ERROR("ShaderProgram could not be found: " << id);
	else
		mp_shader_program = J3D_CACHE_GET(ShaderProgram, id);
	m_enabled = true;
}

UniformBindings::~UniformBindings() {}

////////////////////////////////////////
// ASSIGN

UniformBindings *UniformBindings::assignUniform(string key, vec2 *v)
{
	m_vec2_list[key] = v;
	return this;
}

UniformBindings *UniformBindings::assignUniform(string key, vec3 *v)
{
	m_vec3_list[key] = v;
	return this;
}

UniformBindings *UniformBindings::assignUniform(string key, vec4 *v)
{
	m_vec4_list[key] = v;
	return this;
}

UniformBindings *UniformBindings::assignUniform(string key, mat4 *m)
{
	m_mat4_list[key] = m;
	return this;
}

////////////////////////////////////////
// RUN

void UniformBindings::bindUniforms()
{
	if (!m_enabled || mp_shader_program == nullptr)
		return;
	for (auto it = m_vec2_list.begin(); it != m_vec2_list.end(); ++it)
		mp_shader_program->bind(it->first.c_str(), *it->second);
	for (auto it = m_vec3_list.begin(); it != m_vec3_list.end(); ++it)
		mp_shader_program->bind(it->first.c_str(), *it->second);
	for (auto it = m_vec4_list.begin(); it != m_vec4_list.end(); ++it)
		mp_shader_program->bind(it->first.c_str(), *it->second);
	for (auto it = m_mat4_list.begin(); it != m_mat4_list.end(); ++it)
		mp_shader_program->bind(it->first.c_str(), *it->second);
}

////////////////////////////////////////
// SET GET

UniformBindings *UniformBindings::shaderProgram(ShaderProgram *sp)
{
	mp_shader_program = sp;
	return this;
}

UniformBindings *UniformBindings::enableUniformBindings(bool b)
{
	m_enabled = b;
	return this;
}

UniformBindings *UniformBindings::disableUniformBindings(bool b)
{
	return enableUniformBindings(!b);
}

const ShaderProgram *UniformBindings::shaderProgram() const
{
	return mp_shader_program;
}

bool UniformBindings::uniformBindingsEnabled() const
{
	return m_enabled;
}

} }
