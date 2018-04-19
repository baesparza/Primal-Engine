#version 330 core

layout(location = 0) out vec4 color;

uniform vec2 light_pos;

in DATA
{
	vec4 position;
	vec2 texCoord;
	vec4 color;
} FS_IN;

uniform sampler2D tex;

void main()
{
	float intensity = 1.0f / length(FS_IN.position.xy - light_pos);
	color = FS_IN.color * intensity;
	color = texture(tex, FS_IN.texCoord) * intensity;
}