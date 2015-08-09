/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/shader.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* SHADER
*******************************************************************************/

ShaderProgram::Shader::Shader(const char *path, GLenum type)
		: util::Cacheable(J3D_CACHE_ID, path)
{
	o_type = type;
	o_id = glCreateShader(type);
	const char *source = util::file_get_contents(path, true);
	glShaderSource(o_id, 1, &source, nullptr);
	glCompileShader(o_id);
	GLint compiled;
	glGetShaderiv(o_id, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLsizei len;
		glGetShaderiv(o_id, GL_INFO_LOG_LENGTH, &len);
		GLchar *log = new GLchar[len + 1];
		glGetShaderInfoLog(o_id, len, &len, log);
		J3D_DEBUG_FATAL("(" << cacheIdFull() << ") compilation failed:\n"
				<< log);
		delete [] log;
	}
	J3D_DEBUG_OK("(" << cacheIdFull() << ") compiled");
}

ShaderProgram::Shader::~Shader() {}

GLenum ShaderProgram::Shader::type() const { return o_type; }
GLuint ShaderProgram::Shader::id() const { return o_id; }

/*******************************************************************************
* SHADERPROGRAM
*******************************************************************************/

ShaderProgram::ShaderProgram()
{
	for (int i = 0; i < SHADER_COUNT; ++i)
		mp_shaders[i] = nullptr;
	m_id = glCreateProgram();
	m_linked = false;
}

ShaderProgram::~ShaderProgram()
{
	for (int i = 0; i < SHADER_COUNT; ++i)
		if (mp_shaders[i] != nullptr)
			delete mp_shaders[i];
}

////////////////////////////////////////
// ADD

ShaderProgram *ShaderProgram::addVertexShader(const char *path)
{
	if (J3D_CACHE_HAS(Shader, path))
		mp_shaders[0] = J3D_CACHE_GET(Shader, path);
	else
		mp_shaders[0] = new VertexShader(path);
	glAttachShader(m_id, mp_shaders[0]->id());
	return this;
}

ShaderProgram *ShaderProgram::addFragmentShader(const char *path)
{
	if (J3D_CACHE_HAS(Shader, path))
		mp_shaders[1] = J3D_CACHE_GET(Shader, path);
	else
		mp_shaders[1] = new FragmentShader(path);
	glAttachShader(m_id, mp_shaders[1]->id());
	return this;
}

////////////////////////////////////////
// LINK

void ShaderProgram::link(initializer_list<const char *> unames, bool use)
{
	if (m_linked)
		J3D_DEBUG_WARN("shader program already linked [" << m_id <<
			"], linking again");
	glLinkProgram(m_id);
	GLint linked;
	glGetProgramiv(m_id, GL_LINK_STATUS, &linked);
	if (!linked) {
		GLsizei len;
		glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &len);
		GLchar *log = new GLchar[len + 1];
		glGetProgramInfoLog(m_id, len, &len, log);
		J3D_DEBUG_FATAL("shader program could not be linked:\n" << log);
		delete [] log;
	}
	for (const char *u : unames)
		m_ulocs[string(u)] = glGetUniformLocation(m_id, u);
	m_linked = true;
	J3D_DEBUG_OK("shader program linked [" << m_id << "]");
	if (use)
		glUseProgram(m_id);
}

void ShaderProgram::use()
{
	if (!m_linked) {
		J3D_DEBUG_ERROR("shader program must first be linked [" << m_id << "]");
		return;
	}
	glUseProgram(m_id);
	J3D_DEBUG_OK("using shader program [" << m_id << "]");
}


////////////////////////////////////////
// BIND

bool ShaderProgram::hasUniform(const char *key, bool debug_fatal)
{
	try {
		m_ulocs.at(string(key));
	} catch (...) {
		if (debug_fatal)
			J3D_DEBUG_FATAL("uniform does not exist: " << key);
		return false;
	}
	return true;
}

ShaderProgram *ShaderProgram::bind(const char *key, vec4 v)
{
	glUniform4fv(m_ulocs.at(key), 1, v.glFloat());
	return this;
}

ShaderProgram *ShaderProgram::bind(const char *key, mat4 m)
{
	glUniformMatrix4fv(m_ulocs.at(key), 1, GL_FALSE, m.glFloat());
	return this;
}

////////////////////////////////////////
// GET SET

GLuint ShaderProgram::id() const { return m_id; }
bool ShaderProgram::linked() const { return m_linked; }

GLint ShaderProgram::uloc(const char *key) const
{
	return m_ulocs.at(string(key));
}

}
