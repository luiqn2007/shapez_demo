#version 440 core

layout (location = 1) uniform sampler2D tex;

layout (location = 2) uniform float alpha;

in vec2 fUV;

out vec4 color;

void main() {
    if (fUV.x > 1 || fUV.x < -1) discard;
    if (fUV.y > 1 || fUV.y < -1) discard;

    vec4 tColor = texture(tex, fUV);
    color = vec4(tColor.rgb, tColor.a * alpha);
}