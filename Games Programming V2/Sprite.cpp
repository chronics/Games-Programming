#include "Sprite.h"
#include "Error.h"


Sprite::Sprite()
{
	_VBOID = 0;
}


Sprite::~Sprite()
{
	if (_VBOID != 0)
	{
		glDeleteBuffers(1, &_VBOID);
	}
}

void Sprite::init(float _spriteX, float _spriteY, float _spriteWidth, float _spriteHight)
{
	_X = _spriteX;
	_Y = _spriteY;
	_width = _spriteWidth;
	_hight = _spriteHight;

	if (_VBOID == 0)
	{
		glGenBuffers(1, &_VBOID);
	}

	float vertexData2D[12];

	vertexData2D[0] = _spriteX + _spriteWidth;
	vertexData2D[1] = _spriteY + _spriteHight;

	vertexData2D[2] = _spriteX;
	vertexData2D[3] = _spriteY + _spriteHight;

	vertexData2D[4] = _spriteX;
	vertexData2D[5] = _spriteY;


	vertexData2D[6] = _spriteX;
	vertexData2D[7] = _spriteY;

	vertexData2D[8] = _spriteX + _spriteWidth;
	vertexData2D[9] = _spriteY;

	vertexData2D[10] = _spriteX + _spriteWidth;
	vertexData2D[11] = _spriteY + _spriteHight;

	glBindBuffer(GL_ARRAY_BUFFER, _VBOID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData2D), vertexData2D, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _VBOID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0 ,6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}