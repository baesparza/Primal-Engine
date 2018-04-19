#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA
{
	vec4 position;
	vec2 texCoord;
	vec4 color;
} VS_OUT;

void main()
{
	gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
	VS_OUT.texCoord = texCoord;
	VS_OUT.position = ml_matrix * position;
	VS_OUT.color = color;
}