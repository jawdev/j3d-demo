#version 330 core

uniform vec4 v4_color = vec4(1, 1, 1, 1);

layout (location = 0) in vec2 position;

out vec4 vs_fs_color;

void main(void)
{
	vs_fs_color = v4_color;
	gl_Position = vec4(position.x, position.y, 0, 1);
}
