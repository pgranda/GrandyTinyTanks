#include "Sprite.h"
/**
Sets the Sprite Layer.

@param a_uiLayer Layer on which our player should be drawn.
*/
void Sprite::SetLayer(unsigned int a_uiLayer)
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}

/**
Updates the position of objects in the world.

@param a_fdt DeltaTime of the main program.
*/
void Sprite::Update(float a_fdt)
{
	//OpenGL which is the underlying rendering pipeline that is being used by the framework
	//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
	//from the 3x3 matrix that we are using internally
	//set the sprites matrix

	Matrix3 worldTx = Matrix3::IDENTITY;
	GetWorldTransform(worldTx);
	Vector3 row1, row2, row3;
	worldTx.GetRow(0, row1);
	worldTx.GetRow(1, row2);
	worldTx.GetRow(2, row3);
	Matrix4 m4x4 = Matrix4(row1.GetX(), row1.GetY(), row1.GetZ(), 0.f,
		row2.GetX(), row2.GetY(), row2.GetZ(), 0.f,
		0.f, 0.f, 1.f, 0.f,
		row3.GetX(), row3.GetY(), 0.f, 1.f);
	UG::SetSpriteMatrix(m_iSpriteID, m4x4);
}

/**
Changes sprite position in the world.

@param a_movementVec Sprites movement vector.
*/
void Sprite::MoveSprite(Vector3 a_movementVec)
{
	Vector3 pos;
	m3PosRot.GetRow(2, pos);
	//Multiplying the movement vector by our local transform will put that vector in the local space of this object
	//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
	//of our worldspace matrix
	pos = pos + a_movementVec * m3PosRot;

	m3PosRot.SetRow(2, pos);
}

/**
Draws the sprite.
*/
void Sprite::MarkForDraw()
{
	isDrawing = true;
	UG::DrawSprite(m_iSpriteID);
}

/**
Stops drawing the sprite.
*/
void Sprite::StopDrawing()
{
	isDrawing = false;
	UG::StopDrawingSprite(m_iSpriteID);
}

/**
Destroys the sprite.
*/
void Sprite::DestroySprite()
{
	UG::DestroySprite(m_iSpriteID);
}

/**
Sets sprite positions
*/
void Sprite::SetPosition(Vector2 a_pos)
{
	Vector3 np = Vector3(a_pos.GetX(), a_pos.GetY(), 1.f);
	m3PosRot.SetRow(2, np);
}

/**
Gets isDrawing flag state.

@return isDrawing Returns the flag which determines if the sprite is being drawn.
*/
bool Sprite::GetIsDrawing()
{
	return isDrawing;
}

Sprite::Sprite(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, Vector4 a_UVCoords)
{
	m_iSpriteID = UG::CreateSprite(a_fileName, Vector2((float)(a_width), (float)(a_height)), a_origin, a_UVCoords);
	float mat4x4[16];
	memset(mat4x4, 0, sizeof(float) * 16);
	UG::GetSpriteMatrix(m_iSpriteID, mat4x4);
	m3PosRot = Matrix3(mat4x4[0], mat4x4[1], mat4x4[2], mat4x4[4], mat4x4[5], mat4x4[6], mat4x4[12], mat4x4[13], 1.f);
}

Sprite::Sprite(const char* a_fileName, int a_width, int a_height, Vector2 a_origin)
{
	m_iSpriteID = UG::CreateSprite(a_fileName, Vector2((float)(a_width), (float)(a_height)), a_origin);
	float mat4x4[16];
	memset(mat4x4, 0, sizeof(float) * 16);
	UG::GetSpriteMatrix(m_iSpriteID, mat4x4);
	m3PosRot = Matrix3(mat4x4[0], mat4x4[1], mat4x4[2], mat4x4[4], mat4x4[5], mat4x4[6], mat4x4[12], mat4x4[13], 1.f);
}
/**
Sets Sprite UV Coordinates

@param a_animFrames Array of UV coordinates on sprite sheet.
*/
void Sprite::SetSpriteUVCoordinates(float* a_animFrames)
{
	UG::SetSpriteUVCoordinates(m_iSpriteID, a_animFrames);
}

Sprite::~Sprite()
{
	UG::DestroySprite(m_iSpriteID);
}