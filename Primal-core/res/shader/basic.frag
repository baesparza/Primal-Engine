#version 330 core

layout(location = 0) out vec4 color;

uniform vec2 light_pos;

in DATA
{
	vec4 position;
	vec2 texCoord;
	float texID;
	vec4 color;
} FS_IN;

uniform sampler2D textures[32];

void main()
{
	float intensity = 1.0f / length(FS_IN.position.xy - light_pos);
	vec4 texColor = FS_IN.color;
	if (FS_IN.texID > 0.0)
	{
		int texID = int(FS_IN.texID - 0.5);
		texColor = FS_IN.color * texture(textures[texID], FS_IN.texCoord);
	}
	color = texColor;// * intensity;
}