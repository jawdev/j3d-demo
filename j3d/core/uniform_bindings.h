/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/uniform_bindings.h
*******************************************************************************/
#ifndef __J3D_CORE_UNIFORM_BINDINGS_H__
#define __J3D_CORE_UNIFORM_BINDINGS_H__
namespace j3d { namespace core {

/*******************************************************************************
* SHADERPROFILE
*******************************************************************************/

class UniformBindings {
public:
	UniformBindings(ShaderProgram * = nullptr);
	UniformBindings(string id);
	~UniformBindings();

	UniformBindings *assignUniform(string key, vec2 *);
	UniformBindings *assignUniform(string key, vec3 *);
	UniformBindings *assignUniform(string key, vec4 *);
	UniformBindings *assignUniform(string key, mat4 *);

	void bindUniforms();

	UniformBindings *shaderProgram(ShaderProgram *);
	UniformBindings *enableUniformBindings(bool b = true);
	UniformBindings *disableUniformBindings(bool b = true);

	const ShaderProgram *shaderProgram() const;
	bool uniformBindingsEnabled() const;
	
private:
	ShaderProgram *mp_shader_program;
	bool m_enabled;
	unordered_map<string, vec2 *> m_vec2_list;
	unordered_map<string, vec3 *> m_vec3_list;
	unordered_map<string, vec4 *> m_vec4_list;
	unordered_map<string, mat4 *> m_mat4_list;

};

} }
#endif
