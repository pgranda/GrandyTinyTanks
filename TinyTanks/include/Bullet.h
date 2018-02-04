#ifndef _BULLET_H_
#define _BULLET_H_

#include "Sprite.h"
#include "Shape.h"

class Bullet : public Sprite, public Shape
{
public:
	Bullet(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, std::vector<Vector4> a_animationFrames, int a_damage);
	float GetWidth();
	void SetWidth(float a_width);

	float GetHeight();
	void SetHeight(float a_height);

	bool GetIsShot();
	void SetIsShot(bool a_isShot);

	int GetDamage();
	void SetDamage(int a_damage);

	void SetSpriteIndex(int a_spriteIndex);

	void UpdateBullet(float a_fDeltaTime);

	void Shoot(Vector2 a_position, Vector3 a_movementVector);
	void Move();
	void AnimateExplosion();
	void MarkAsExploding();

private:
	bool isExploding = false;
	float fWidth = 25;
	float fHeight = 25;
	bool isShot = false;
	int damage = 0;
	Vector3 movementVector;
	int spriteIndex;
	std::vector<Vector4> animationFrames;
	Sprite* explosion;
};

#endif _BULLET_H_