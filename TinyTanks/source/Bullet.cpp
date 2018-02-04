#include "Bullet.h"

/**
Getter that returns bullets width.

@return fWidth Bullets width.
*/
float Bullet::GetWidth()
{
	return fWidth;
}

/**
Setter which sets the bullets width.

@param a_width Value that we want to pass as width of bullet.
*/
void Bullet::SetWidth(float a_width)
{
	fWidth = a_width;
}

/**
Getter that return bullets height

@return fHeight Bullets height
*/
float Bullet::GetHeight()
{
	return fHeight;
}

/**
Setter which sets the bullets height.

@param a_height Value that we want to pass as height of bullet.
*/
void Bullet::SetHeight(float a_height)
{
	fHeight = a_height;
}

/**
Getter that returns flag saying if bullet was shot.

@return isShot Was bullet shot.
*/
bool Bullet::GetIsShot()
{
	return isShot;
}

/**
Setter which sets the isShot flag, indicating if the bullet was shot or not.

@param a_isShot was the bullet shot.
*/
void Bullet::SetIsShot(bool a_isShot)
{
	isShot = a_isShot;
}

/**
Getter that returns damage dealt.

@return damage Value of bullet damage.
*/
int Bullet::GetDamage()
{
	return damage;
}

/**
Setter which sets the damage value.

@param a_damage Damage points.
*/
void Bullet::SetDamage(int a_damage)
{
	damage = a_damage;
}

/**
Setter which sets the spriteIndex value to the one given as parameter.

@param a_spriteIndex index of UV coordinates row in vector.
*/
void Bullet::SetSpriteIndex(int a_spriteIndex)
{
	spriteIndex = a_spriteIndex;
}

/**
Function which updates bullet location or explosion animation.
*/
void Bullet::UpdateBullet(float a_fDeltaTime)
{
	if (GetIsDrawing())
	{
		Update(a_fDeltaTime);
	}
	if (isExploding)
	{
		explosion->Update(a_fDeltaTime);
	}
}

/**
Function which sets the initial bullet position, draws it, sets layer, sets isShot flag and moves the bullet.
*/
void Bullet::Shoot(Vector2 a_position, Vector3 a_movementVector)
{
	SetPosition(a_position);
	movementVector = a_movementVector;
	MarkForDraw();
	SetLayer(3);
	SetIsShot(true);
	movementVector = movementVector * 10;
	MoveSprite(movementVector);
}

/**
Function which moves the Bullet sprite by given movement vector.
*/
void Bullet::Move()
{
	MoveSprite(movementVector);
}

/**
Function which iterates through animationFrames vector of UV coordinates, performing animation on sprite.
*/
void Bullet::AnimateExplosion()
{
	if (spriteIndex == animationFrames.size()-1)
	{
		isExploding = false;
		explosion->StopDrawing();
		spriteIndex = 0;
		return;
	}
	if (isExploding)
	{
		if (spriteIndex == 0)
		{
			Vector3 zAxis;
			this->m3PosRot.GetRow(2, zAxis);
			explosion->SetPosition(Vector2(zAxis.GetX(), zAxis.GetY()));
			explosion->SetLayer(3);
			explosion->MarkForDraw();
		}
		spriteIndex = spriteIndex + 1;
		explosion->SetSpriteUVCoordinates(animationFrames.at(spriteIndex));
	}
}

/**
Function which marks the bullet as exploding one and stops drawing the sprite.
*/
void Bullet::MarkAsExploding()
{
	isExploding = true;
	StopDrawing();
}

Bullet::Bullet(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, std::vector<Vector4> a_animationFrames, int a_damage)
	:Sprite(a_fileName, a_width, a_height, a_origin, a_animationFrames.at(0)), Shape((float)(a_width), (float)(a_height))
{
	animationFrames = a_animationFrames;
	spriteIndex = 0;
	movementVector = Vector3::AXIS_Y;
	damage = a_damage;
	explosion = new Sprite("./images/bullet1.png", 25, 25, Vector2(0.5f, 0.5f), animationFrames.at(1));
}