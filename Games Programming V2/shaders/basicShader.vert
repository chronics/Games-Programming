#version 140

in vec2 vertexPostion;

void main() 
{
	gl_Positon.xy = vertexPostion;
	gl_Positon.z = 0;
	gl_Positon.w = 1;
}