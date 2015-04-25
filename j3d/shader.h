/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /shader.h
******************************************************************************/
#ifndef J3D_SHADER_H_
#define J3D_SHADER_H_
namespace j3d {

class Shader {
public:

	Shader( const char* path, GLenum type );
	virtual ~Shader();

	GLuint id();
	GLenum type();

protected:
	GLuint m_id;
	GLenum m_type;
};

class VertexShader : public Shader {
public:
	VertexShader( const char* path ) : Shader( path, GL_VERTEX_SHADER ) {}
};

class FragmentShader : public Shader {
public:
	FragmentShader( const char* path ) : Shader( path, GL_FRAGMENT_SHADER ) {}
};

class ShaderProgram {
public:
	static const int SHADER_COUNT = 2;
public:
	ShaderProgram();
	~ShaderProgram();

	ShaderProgram* addVertexShader( const char* path );
	ShaderProgram* addFragmentShader( const char* path );

	void link( initializer_list<char*> unames );

	GLuint id();
	bool linked();

private:
	GLuint m_id;
	Shader* mp_shaders[SHADER_COUNT];
	bool m_linked;
	map<char*,GLint> m_ulocs;
};


}
#endif
