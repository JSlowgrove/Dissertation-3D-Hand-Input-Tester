#version 430 core

uniform vec3 inColour
out vec4 fColor;

void main(){ 
	fColor = vec4(inColour.x,inColour.y,inColour.z,1.0); 
}