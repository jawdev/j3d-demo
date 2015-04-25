/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /shader.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

Shader::Shader( const char* path, GLenum type ) {
	GLuint id = glCreateShader( type );
	const char* source = util::file_get_contents( path, true );
	glShaderSource( id, 1, &source, nullptr );
	glCompileShader( id );
	GLint compiled;
	glGetShaderiv( id, GL_COMPILE_STATUS, &compiled );
	if( !compiled ) {
		GLsizei len;
		glGetShaderiv( id, GL_INFO_LOG_LENGTH, &len );
		GLchar* log = new GLchar[len+1];
		glGetShaderInfoLog( id, len, &len, log );
		cerr << log << endl;
		debug::fatal << "(Shader::Shader) compilation failed: " << path << "\n" << log << debug::flush;
		delete [] log;
	}
	m_id = id;
	m_type = type;
}

Shader::~Shader() {}

GLuint Shader::id() { return m_id; }
GLenum Shader::type() { return m_type; }

ShaderProgram::ShaderProgram() {
	for( int i = 0; i < SHADER_COUNT; i++ ) mp_shaders[i] = nullptr;
	m_id = glCreateProgram();
	m_linked = false;
}

ShaderProgram::~ShaderProgram() {
	for( int i = 0; i < SHADER_COUNT; i++ ) SAFE_DELETE( mp_shaders[i] );
}

ShaderProgram* ShaderProgram::addVertexShader( const char* path ) {
	mp_shaders[0] = new VertexShader( path );
	glAttachShader( m_id, mp_shaders[0]->id() );
	return this;
}

ShaderProgram* ShaderProgram::addFragmentShader( const char* path ) {
	mp_shaders[1] = new FragmentShader( path );
	glAttachShader( m_id, mp_shaders[1]->id() );
	return this;
}

void ShaderProgram::link( initializer_list<char*> unames ) {
	glLinkProgram( m_id );
	GLint linked;
	glGetProgramiv( m_id, GL_LINK_STATUS, &linked );
	if( !linked ) {
		GLsizei len;
		glGetProgramiv( m_id, GL_INFO_LOG_LENGTH, &len );
		GLchar* log = new GLchar[len+1];
		glGetProgramInfoLog( m_id, len, &len, log );
		cerr << log << endl;
		debug::fatal << "(ShaderProgram::link) shader program could not be linked\n" << log << debug::flush;
		delete [] log;
	}
	for( char* uname : unames ) {
		m_ulocs.insert( pair<char*,GLint>( uname, glGetUniformLocation( m_id, uname ) ) );
	}
	m_linked = true;
}

GLuint ShaderProgram::id() { return m_id; }
bool ShaderProgram::linked() { return m_linked; }

}
