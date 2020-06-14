#include "Enemy_Barrel.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "Enemy.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int direction) : Enemy(x, y)
{
	BarrelAnim.PushBack({ 103, 136, 12, 10 });
	BarrelAnim.PushBack({ 116, 136, 12, 10 });
	BarrelAnim.PushBack({ 129, 136, 12, 10 });
	BarrelAnim.PushBack({ 142, 136, 12, 10 });
	BarrelAnim.loop = true;
	BarrelAnim.speed = 0.1f;

	BarrelFall.PushBack({ 92, 153, 16, 11 });
	BarrelFall.PushBack({ 92, 153, 16, 11 });
	BarrelFall.loop = true;
	BarrelFall.speed = 0.1f;

	currentAnim = &BarrelAnim;


	collider = App->collisions->AddCollider({ 0, 0, 8, 8 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


// Call to the base class. It must be called at the end
// It will update the collider depending on the position
void Enemy_Barrel::UpdateState()
{
	srand(time(NULL));
	if (enemyCanFall == true)
	{


	randomValue = rand() % 3;

		if (randomValue == 0)
		{
		ChangeState(ENEMY_MOVING, ENEMY_FALLING);
		}
	}

	if (enemyHitRight == true)
	{
		randomValue = rand() % 3;

		if (randomValue == 0)
		{
			facingDirection *= -1;
		}
	}

	if (enemyHitLeft == true)
	{
		randomValue = rand() % 3;

		if (randomValue == 0)
		{
			facingDirection *= -1;
		}
	}

}

void Enemy_Barrel::ChangeState(Enemy_State prevState, Enemy_State newState)
{
	switch (newState)
	{
	case ENEMY_MOVING:
		currentAnim = &BarrelAnim;
		break;
	case ENEMY_FALLING:
		currentAnim = &BarrelFall;
		break;
	}
}

void Enemy_Barrel::UpdateLogic()
{
	switch (state)
	{
	case ENEMY_MOVING:
		if (rampRight == true)
		{
			//Left
			if (facingDirection == -1)
			{
				if (collider->rect.y <= aux.y - 8 && collider->rect.x + 4 == aux.x) //Go Down Looking Left//
				{
					position.y += speed;
				}
			}
		}

		if (rampLeft == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (collider->rect.y <= aux.y - 8 && collider->rect.x + 5 == aux.x) //Go Down Looking Right
				{
					position.y += speed;
				}
			}
		}

		position.x += speed * facingDirection;
		currentAnim->Update();

		break;

	case ENEMY_FALLING:
		position.y += speed;
		 
		break;
	}
}

