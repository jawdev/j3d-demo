#version 330 core

uniform vec3 v3_ambient = vec3( 0.1, 0.1, 0.1 );
uniform vec3 v3_light_color = vec3( 1, 1, 1 );
uniform vec3 v3_light_dir = vec3( 0.5, -1, -0.2 );

in vec4 vs_fs_color;
in vec3 vs_fs_normal;

layout (location=0) out vec4 fColor;

void main() {
	float diffuse = max( 0.0, dot( -vs_fs_normal, v3_light_dir ) );
	vec3 scat = v3_ambient+v3_light_color*diffuse;
	vec3 rgb = min( vs_fs_color.rgb*scat, vec3( 1 ) );
	fColor = vec4( rgb, vs_fs_color.a );
}