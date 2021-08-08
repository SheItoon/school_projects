#version 100

attribute vec3 vertexPosition;

uniform mat4 projection;
uniform mat4 view;

varying vec3 fragPosition;

void main()
{
    fragPosition = vertexPosition;

    gl_Position = projection*view*vec4(vertexPosition, 1.0);
}