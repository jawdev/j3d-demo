/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/shader.h
*******************************************************************************/
#ifndef __J3D_SHADER_H__
#define __J3D_SHADER_H__
namespace j3d {

/*******************************************************************************
* SHADERPROGRAM
*******************************************************************************/

class ShaderProgram {
public:
	static const int SHADER_COUNT = 2;

public:
	class Shader : public core::Cacheable {
	public:
		static const char constexpr *J3D_CACHE_ID = "shader";

	public:
		Shader(const char *path, GLenum type);
		virtual ~Shader();

		GLenum type() const;
		GLuint id() const;

	protected:
		GLenum o_type;
		GLuint o_id;

	};

	class VertexShader : public Shader {
	public:
		VertexShader(const char *path) : Shader(path, GL_VERTEX_SHADER) {}
	};

	class FragmentShader : public Shader {
	public:
		FragmentShader(const char *path) : Shader(path, GL_FRAGMENT_SHADER) {}
	};


public:
	ShaderProgram();
	~ShaderProgram();

	ShaderProgram *addVertexShader(const char *path);
	ShaderProgram *addFragmentShader(const char *path);

	void link(initializer_list<const char *> unames, bool use = true);
	void use();

	bool hasUniform(const char *key, bool debug_fatal = true);
	ShaderProgram *bind(const char *key, vec4 v);
	ShaderProgram *bind(const char *key, mat4 m);

	GLuint id() const;
	bool linked() const;
	GLint uloc(const char *key) const;

private:
	GLuint m_id;
	Shader *mp_shaders[SHADER_COUNT];
	bool m_linked;
	unordered_map<string, GLint> m_ulocs;

};

}
#endif
