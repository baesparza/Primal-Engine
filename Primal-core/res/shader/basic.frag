#version 330 core

layout(location = 0) out vec4 color;

uniform vec2 light_pos;

in DATA
{
	vec4 position;
	vec4 color;
} FS_IN;

void main()
{
	float intensity = 1.0f / length(FS_IN.position.xy - light_pos);
	color = FS_IN.color * intensity;
}