#pragma once

#include <string>
#include <SDL2/SDL.h>

//note culling is enabled with the counterclockwise rotation, plan accordingly (x, y, z, w)
const float tankbodyGreen[] = {

#pragma region body 
	//face top A
	0.2f, 0.25f, -0.2f, 1.0f, //top right
	0.2f, -0.25f, -0.2f, 1.0f, //bottom right
	-0.2f, 0.25f, -0.2f, 1.0f, //top left

	//face top B
	-0.2f, 0.25f, -0.2f, 1.0f, //top left
	0.2f, -0.25f, -0.2f, 1.0f, //bottom right
	-0.2f, -0.25f, -0.2f, 1.0f, // bottom left


	//face bottom A
	0.2f, 0.25f, 0.2f, 1.0f, //top right
	-0.2f, 0.25f, 0.2f, 1.0f, //top left
	0.2f, -0.25f, 0.2f, 1.0f, //bottom right

	//face bottom B
	-0.2f, 0.25f, 0.2f, 1.0f, //top left
	-0.2f, -0.25f, 0.2f, 1.0f, // bottom left
	0.2f, -0.25f, 0.2f, 1.0f, //bottom right


	//face left A (side)
	-0.2f, 0.25f, 0.2f, 1.0f, //top right
	-0.2f, 0.25f, -0.2f, 1.0f, //top left
	-0.2f, -0.25f, 0.2f, 1.0f, // bottom right

	//face left A (side)
	-0.2f, -0.25f, 0.2f, 1.0f, // bottom right
	-0.2f, 0.25f, -0.2f, 1.0f, //top left
	-0.2f, -0.25f, -0.2f, 1.0f, //bottom left


	//face right A (side)
	0.2f, 0.25f, 0.2f, 1.0f, //top right
	0.2f, -0.25f, 0.2f, 1.0f, // bottom right
	0.2f, 0.25f, -0.2f, 1.0f, //top left

	//face right A (side)
	0.2f, -0.25f, 0.2f, 1.0f, // bottom right
	0.2f, -0.25f, -0.2f, 1.0f, //top left
	0.2f, 0.25f, -0.2f, 1.0f, //top left


	//face  front A
	0.2f, 0.25f, -0.2f, 1.0f, //front top right
	-0.2f, 0.25f, 0.2f, 1.0f, //front top left
	0.2f, 0.25f, 0.2f, 1.0f,//front bottom right

	//face  front 
	0.2f, 0.25f, -0.2f, 1.0f, //front top right
	-0.2f, 0.25f, -0.2f, 1.0f, //front top left
	-0.2f, 0.25f, 0.2f, 1.0f,//front bottom right


	//back face A
	0.2f, -0.25f, 0.2f, 1.0f, //front top right
	-0.2f, -0.25f, 0.2f, 1.0f, //front top left
	-0.2f, -0.25f, -0.2f, 1.0f,//front bottom right

	0.2f, -0.25f, 0.2f, 1.0f, //front top right
	-0.2f, -0.25f, -0.2f, 1.0f, //front top left
	0.2f, -0.25f, -0.2f, 1.0f,//front bottom right
#pragma endregion

#pragma region cannon
	//top face Main
	- 0.15f, 0.05f, 0.3f, 1.0f,
	0.15f, 0.05f, 0.3f, 1.0f,
	-0.15f, 0.2f, 0.3f, 1.0f,

	-0.15f, 0.2f, 0.3f, 1.0f,
	0.15f, 0.05f, 0.3f, 1.0f,
	0.15f, 0.2f, 0.3f, 1.0f,


	//top face barrel
	-0.04f, 0.05f, 0.3f, 1.0f,
	-0.04f, -0.1f, 0.3f, 1.0f,
	0.04f, -0.1f, 0.3f, 1.0f,

	0.04f, -0.1f, 0.3f, 1.0f,
	0.04f, 0.05f, 0.3f, 1.0f,
	-0.04f, 0.05f, 0.3f, 1.0f,

	//top face muzzel
	0.07f, -0.1f, 0.3f, 1.0f,
	-0.07f, -0.1f, 0.3f, 1.0f,
	0.07f, -0.15f, 0.3f, 1.0f,

	0.07f, -0.15f, 0.3f, 1.0f,
	-0.07f, -0.1f, 0.3f, 1.0f,
	-0.07f, -0.15f, 0.3f, 1.0f,




#pragma endregion

#pragma region colour data
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

	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,


	//light blue
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,


	//cannon main
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,


	//cannon barrel
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	//cannon muzzel
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,


#pragma endregion
};


const float tankbodyRed[] = {

#pragma region body 
	//face top A
	0.2f, 0.25f, -0.2f, 1.0f, //top right
	0.2f, -0.25f, -0.2f, 1.0f, //bottom right
	-0.2f, 0.25f, -0.2f, 1.0f, //top left

	//face top B
	-0.2f, 0.25f, -0.2f, 1.0f, //top left
	0.2f, -0.25f, -0.2f, 1.0f, //bottom right
	-0.2f, -0.25f, -0.2f, 1.0f, // bottom left


	//face bottom A
	0.2f, 0.25f, 0.2f, 1.0f, //top right
	-0.2f, 0.25f, 0.2f, 1.0f, //top left
	0.2f, -0.25f, 0.2f, 1.0f, //bottom right

	//face bottom B
	-0.2f, 0.25f, 0.2f, 1.0f, //top left
	-0.2f, -0.25f, 0.2f, 1.0f, // bottom left
	0.2f, -0.25f, 0.2f, 1.0f, //bottom right


	//face left A (side)
	-0.2f, 0.25f, 0.2f, 1.0f, //top right
	-0.2f, 0.25f, -0.2f, 1.0f, //top left
	-0.2f, -0.25f, 0.2f, 1.0f, // bottom right

	//face left A (side)
	-0.2f, -0.25f, 0.2f, 1.0f, // bottom right
	-0.2f, 0.25f, -0.2f, 1.0f, //top left
	-0.2f, -0.25f, -0.2f, 1.0f, //bottom left


	//face right A (side)
	0.2f, 0.25f, 0.2f, 1.0f, //top right
	0.2f, -0.25f, 0.2f, 1.0f, // bottom right
	0.2f, 0.25f, -0.2f, 1.0f, //top left

	//face right A (side)
	0.2f, -0.25f, 0.2f, 1.0f, // bottom right
	0.2f, -0.25f, -0.2f, 1.0f, //top left
	0.2f, 0.25f, -0.2f, 1.0f, //top left


	//face  front A
	0.2f, 0.25f, -0.2f, 1.0f, //front top right
	-0.2f, 0.25f, 0.2f, 1.0f, //front top left
	0.2f, 0.25f, 0.2f, 1.0f,//front bottom right

	//face  front 
	0.2f, 0.25f, -0.2f, 1.0f, //front top right
	-0.2f, 0.25f, -0.2f, 1.0f, //front top left
	-0.2f, 0.25f, 0.2f, 1.0f,//front bottom right


	//back face A
	0.2f, -0.25f, 0.2f, 1.0f, //front top right
	-0.2f, -0.25f, 0.2f, 1.0f, //front top left
	-0.2f, -0.25f, -0.2f, 1.0f,//front bottom right

	0.2f, -0.25f, 0.2f, 1.0f, //front top right
	-0.2f, -0.25f, -0.2f, 1.0f, //front top left
	0.2f, -0.25f, -0.2f, 1.0f,//front bottom right
#pragma endregion

#pragma region cannon
	//top face Main
	- 0.15f, 0.05f, 0.3f, 1.0f,
	0.15f, 0.05f, 0.3f, 1.0f,
	-0.15f, 0.2f, 0.3f, 1.0f,

	-0.15f, 0.2f, 0.3f, 1.0f,
	0.15f, 0.05f, 0.3f, 1.0f,
	0.15f, 0.2f, 0.3f, 1.0f,


	//top face barrel
	-0.04f, 0.05f, 0.3f, 1.0f,
	-0.04f, -0.1f, 0.3f, 1.0f,
	0.04f, -0.1f, 0.3f, 1.0f,

	0.04f, -0.1f, 0.3f, 1.0f,
	0.04f, 0.05f, 0.3f, 1.0f,
	-0.04f, 0.05f, 0.3f, 1.0f,

	//top face muzzel
	0.07f, -0.1f, 0.3f, 1.0f,
	-0.07f, -0.1f, 0.3f, 1.0f,
	0.07f, -0.15f, 0.3f, 1.0f,

	0.07f, -0.15f, 0.3f, 1.0f,
	-0.07f, -0.1f, 0.3f, 1.0f,
	-0.07f, -0.15f, 0.3f, 1.0f,




#pragma endregion

#pragma region colour data
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

	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,


	//light blue
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,


	//cannon main
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,


	//cannon barrel
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	//cannon muzzel
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,

	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,
	1.0f, 0.2f, 1.0f, 1.0f,


#pragma endregion
};

const float cubeGreen[] = {

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
	//green
	0.0f, 0.5f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.1f, 0.0f, 1.0f,

	0.0f, 0.1f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 1.0f,

	0.0f, 0.5f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.1f, 0.0f, 1.0f,

	0.0f, 0.1f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 1.0f,

	0.0f, 0.5f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.1f, 0.0f, 1.0f,

	0.0f, 0.1f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 1.0f,

	0.0f, 0.5f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.1f, 0.0f, 1.0f,

	0.0f, 0.1f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 1.0f,

	0.0f, 0.5f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.1f, 0.0f, 1.0f,

	0.0f, 0.1f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 1.0f,

	0.0f, 0.5f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.1f, 0.0f, 1.0f,

	0.0f, 0.1f, 0.0f, 1.0f,
	0.0f, 0.3f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 1.0f,
};


const float cubeRed[] = {

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
	//red
	0.3f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.4f, 0.0f, 0.0f, 1.0f,

	0.4f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.3f, 0.0f, 0.0f, 1.0f, 

	0.3f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.4f, 0.0f, 0.0f, 1.0f,

	0.4f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.3f, 0.0f, 0.0f, 1.0f,

	0.3f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.4f, 0.0f, 0.0f, 1.0f,

	0.4f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.3f, 0.0f, 0.0f, 1.0f,

	0.3f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.4f, 0.0f, 0.0f, 1.0f,

	0.4f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.3f, 0.0f, 0.0f, 1.0f,

	0.3f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.4f, 0.0f, 0.0f, 1.0f,

	0.4f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.3f, 0.0f, 0.0f, 1.0f,

	0.3f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.4f, 0.0f, 0.0f, 1.0f,

	0.4f, 0.0f, 0.0f, 1.0f,
	0.2f, 0.0f, 0.0f, 1.0f,
	0.3f, 0.0f, 0.0f, 1.0f,
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

const float offsetTank_4X[] = {

	-4.2f, 4.2f, 0.0f, 1.0f,
	-4.0f, 4.2f, 0.0f, 1.0f,
	-4.2f, 4.0f, 0.0f, 1.0f,

	-4.0f, 4.2f, 0.0f, 1.0f,
	-4.0f, 4.0f, 0.0f, 1.0f,
	-4.2f, 4.0f, 0.0f, 1.0f,


	-4.2f, 4.2f, 0.2f, 1.0f,
	-4.0f, 4.2f, 0.2f, 1.0f,
	-4.2f, 4.0f, 0.2f, 1.0f,

	-4.0f, 4.2f, 0.2f, 1.0f,
	-4.0f, 4.0f, 0.2f, 1.0f,
	-4.2f, 4.0f, 0.2f, 1.0f,


	-4.2f, 4.2f, 0.0f, 1.0f,
	-4.2f, 4.2f, 0.2f, 1.0f,
	-4.2f, 4.0f, 0.2f, 1.0f,

	-4.2f, 4.2f, 0.0f, 1.0f,
	-4.2f, 4.0f, 0.2f, 1.0f,
	-4.2f, 4.0f, 0.0f, 1.0f,


	-4.0f, 4.2f, 0.0f, 1.0f,
	-4.0f, 4.2f, 0.2f, 1.0f,
	-4.0f, 4.0f, 0.2f, 1.0f,

	-4.0f, 4.2f, 0.0f, 1.0f,
	-4.0f, 4.0f, 0.2f, 1.0f,
	-4.0f, 4.0f, 0.0f, 1.0f,


	-4.2f, 4.2f, 0.2f, 1.0f,
	-4.0f, 4.2f, 0.2f, 1.0f,
	-4.2f, 4.2f, 0.0f, 1.0f,

	-4.0f, 4.2f, 0.2f, 1.0f,
	-4.0f, 4.2f, 0.0f, 1.0f,
	-4.2f, 4.2f, 0.0f, 1.0f,


	-4.2f, 4.0f, 0.2f, 1.0f,
	-4.0f, 4.0f, 0.2f, 1.0f,
	-4.2f, 4.0f, 0.0f, 1.0f,

	-4.0f, 4.0f, 0.2f, 1.0f,
	-4.0f, 4.0f, 0.0f, 1.0f,
	-4.2f, 4.0f, 0.0f, 1.0f,


	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,


	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,


	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,

	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,


	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,

	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,


	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,

	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,


	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,

	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
	0.0f, 0.2f, 0.0f, 1.0f,
};
const float _waypointQuad[] = {

	0.2f, 0.2f, 0.25f, 1.0f,
	-0.2f, 0.2f, 0.25f, 1.0f,
	-0.2f, -0.2f, 0.25f, 1.0f,

	0.2f, 0.2f, 0.25f, 1.0f,
	-0.2f, -0.2f, 0.25f, 1.0f,
	0.2f, -0.2f, 0.25f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
};
	