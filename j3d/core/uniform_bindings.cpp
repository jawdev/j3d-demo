/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/shader_profile.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace core {

/*******************************************************************************
* SHADERPROFILE
*******************************************************************************/

UniformBindings::UniformBindings(ShaderProgram *p)
{
	mp_shader_program = p;
}

UniformBindings::UniformBindings(string id)
{
	if (!J3D_CACHE2(exists, ShaderProgram, id))
		J3D_DEBUG_ERROR("ShaderProgram could not be found: " << id);
	else
		mp_shader_program = J3D_CACHE_GET(ShaderProgram, id);
}

UniformBindings::~UniformBindings() {}

UniformBindings *UniformBindings::assignBinding(string key, vec2 *v)
{
	m_vec2_list[key] = v;
	return this;
}

UniformBindings *UniformBindings::assignBinding(string key, vec3 *v)
{
	m_vec3_list[key] = v;
	return this;
}

UniformBindings *UniformBindings::assignBinding(string key, vec4 *v)
{
	m_vec4_list[key] = v;
	return this;
}

UniformBindings *UniformBindings::assignBinding(string key, mat4 *m)
{
	m_mat4_list[key] = m;
	return this;
}

void UniformBindings::runBindings()
{
	if (mp_shader_program == nullptr)
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

} }
