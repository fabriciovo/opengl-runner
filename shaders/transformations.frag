#version 450 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Texture sampler
uniform sampler2D ourTexture1;
uniform float offsetx;
uniform float offsety;

void main()
{
    color = texture(ourTexture1, vec2(TexCoord.x + offsetx, TexCoord.y + offsety));// * vec4(ourColor, 1.0);
}