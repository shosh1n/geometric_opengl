#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 vertexColor

uniform float stretch;
unifrom vec2 translation;

void main() {
    vec2 strechted_pos;
    stretched_pos.x = translation.x + position.x + strech;
    stretched_pos.y = translation.y + position.y;
    gl_Position = vec4(stretched_pos.x, strechted_pos.y, position.z, 1.0);

    vertexColor = color;
}
