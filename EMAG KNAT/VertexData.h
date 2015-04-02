#pragma once

#include <string>
#include <SDL2/SDL.h>

//note culling is enabled with the counterclockwise rotation, plan accordingly (x, y, z, w)
const float tankbody[] = {

	//face top A
	0.2f, 0.3f, -0.2f, 1.0f, //top right
	0.2f, -0.2f, -0.2f, 1.0f, //bottom right
	-0.2f, 0.3f, -0.2f, 1.0f, //top left

	//face top B
	-0.2f, 0.3f, -0.2f, 1.0f, //top left
	0.2f, -0.2f, -0.2f, 1.0f, //bottom right
	-0.2f, -0.2f, -0.2f, 1.0f, // bottom left



	//face bottom A
	0.2f, 0.3f, 0.2f, 1.0f, //top right
	-0.2f, 0.3f, 0.2f, 1.0f, //top left
	0.2f, -0.2f, 0.2f, 1.0f, //bottom right

	//face bottom B
	-0.2f, 0.3f, 0.2f, 1.0f, //top left
	-0.2f, -0.2f, 0.2f, 1.0f, // bottom left
	0.2f, -0.2f, 0.2f, 1.0f, //bottom right


	//face left A (side)
	-0.2f, 0.3f, 0.2f, 1.0f, //top right
	-0.2, 0.3f, -0.2f, 1.0f, //top left
	-0.2f, -0.2f, 0.2f, 1.0f, // bottom right

	//face left A (side)
	-0.2f, -0.2f, 0.2f, 1.0f, // bottom right
	-0.2, 0.3f, -0.2f, 1.0f, //top left
	-0.2, -0.2f, -0.2f, 1.0f, //bottom left

	//face right A (side)
	0.2f, 0.3f, 0.2f, 1.0f, //top right
	0.2f, -0.2f, 0.2f, 1.0f, // bottom right
	0.2, 0.3f, -0.2f, 1.0f, //top left

	//face right A (side)
	0.2f, -0.2f, 0.2f, 1.0f, // bottom right
	0.2, -0.2f, -0.2f, 1.0f, //top left
	0.2, 0.3f, -0.2f, 1.0f, //top left

	//face  front A
	-0.2, 0.2f, 0.2f, 1.0f, //front top left
	0.2f, 0.2f, -0.2f, 1.0f, //front top right
	0.2f, 0.2f, 0.2f, 1.0f,//front bottom right

	//colour data
	//blue top
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	//red bottom
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f, 
	
	//green side
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	//yellow face
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,

	//purple face
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,

};

const float cube[] = {

	//body positions
	//face 1
	-0.25f, -0.25f, -0.25f, 1.0f,
	-0.25f, -0.25f, 0.25f, 1.0f,
	-0.25f, 0.25f, 0.25f, 1.0f,

	-0.25f, -0.25f, -0.25f, 1.0f,
	-0.25f, 0.25f, 0.25f, 1.0f,
	-0.25f, 0.25f, -0.25f, 1.0f,

	//face 2
	0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f, -0.25f, -0.25f, 1.0f,
	-0.25f, 0.25f, -0.25f, 1.0f,

	0.25f, 0.25f, -0.25f, 1.0f,
	0.25f, -0.25f, -0.25f, 1.0f,
	-0.25f, -0.25f, -0.25f, 1.0f,

	//face 3
	0.25f, -0.25f, 0.25f, 1.0f,
	-0.25f, -0.25f, -0.25f, 1.0f,
	0.25f, -0.25f, -0.25f, 1.0f,

	0.25f, -0.25f, 0.25f, 1.0f,
	-0.25f, -0.25f, 0.25f, 1.0f,
	-0.25f, -0.25f, -0.25f, 1.0f,

	//face 4
	-0.25f, 0.25f, 0.25f, 1.0f,
	-0.25f, -0.25f, 0.25f, 1.0f,
	0.25f, -0.25f, 0.25f, 1.0f,

	0.25f, 0.25f, 0.25f, 1.0f,
	-0.25f, 0.25f, 0.25f, 1.0f,
	0.25f, -0.25f, 0.25f, 1.0f,

	//face 5
	0.25f, 0.25f, 0.25f, 1.0f,
	0.25f, -0.25f, -0.25f, 1.0f,
	0.25f, 0.25f, -0.25f, 1.0f,

	0.25f, -0.25f, -0.25f, 1.0f,
	0.25f, 0.25f, 0.25f, 1.0f,
	0.25f, -0.25f, 0.25f, 1.0f,

	//face 6
	0.25f, 0.25f, 0.25f, 1.0f,
	0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f, 0.25f, -0.25f, 1.0f,

	0.25f, 0.25f, 0.25f, 1.0f,
	-0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f, 0.25f, 0.25f, 1.0f,



	//colors
	//blue
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
};

const float triangles[] = {

	0.0f, 0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.0f,1.0f,

	//colour
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
};