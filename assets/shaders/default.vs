#version 330 core

uniform mat4 m4_camera;
uniform mat4 m4_model;
uniform vec4 v4_color = vec4( 1, 1, 1, 1 );

layout (location=0) in vec4 position;
layout (location=1) in vec3 normal;

out vec4 vs_fs_color;
out vec3 vs_fs_normal;

void main( void ) {
	vs_fs_color = v4_color;
	vs_fs_normal = mat3( m4_model )*normal;
	gl_Position = m4_camera*m4_model*position;
}
