#version 140

in vec4 position;
in vec4 color;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
smooth out vec4 theColor;
void main()
{
   gl_Position = projectionMatrix * viewMatrix * modelMatrix * position;
   theColor = color; //just pass on the color. It's a **smooth**, so will be interpolated
}