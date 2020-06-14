#include "Enemy_Barrel.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "Enemy.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int _direction) : Enemy(x, y)
{
	direction = _direction;
	
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


	collider = App->collisions->AddCollider({ position.x + 1, position.y + 1, 8, 8 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

Enemy_Barrel::~Enemy_Barrel()
{

}

void Enemy_Barrel::Update()
{
	UpdateState();
	UpdateLogic();
}


// Call to the base class. It must be called at the end
// It will update the collider depending on the position
void Enemy_Barrel::UpdateState()
{
	switch (barrelState)
	{
	case BARREL_MOVING:
		if (canGoDownStairs == true)
		{
			//random = rand() % 10 + 1;
			random = 3;
			if (random <= 3)
			{
				ChangeState(barrelState, BARREL_FALLING);
			}
			canGoDownStairs = false;
		}
		break;

	case BARREL_FALLING:
		if (touchedWall == true)
		{
			position.y -= speed;
			ChangeState(barrelState, BARREL_MOVING);
		}
		break;

	default:
		break;
	}

	Enemy::Update();
}

void Enemy_Barrel::UpdateLogic()
{
	switch (barrelState)
	{
	case BARREL_MOVING:

		if (direction == 1)
		{
			position.x += speed;
		}

		if (direction == -1)
		{
			position.x -= speed;
		}


		//Going Right
		if (rampLeft == true)
		{
			if (collider->rect.y < aux.y - 8 && collider->rect.x + 4 == aux.x) //Go Down Looking Right
			{
				position.y += speed;
			}
		}

		//Going Left
		if (rampRight == true)
		{
			if (collider->rect.y <= aux.y - 8 && collider->rect.x + 5 == aux.x) //Go Down Looking Left//
			{
				position.y += speed;
			}
		}

		currentAnim->Update();

		break;

	case BARREL_FALLING:
		if (touchedWall == false)
		{
			position.y += speed;
		}

		currentAnim->Update();

		break;

	default:
		break;
	}

	rampRight = false;
	rampLeft = false;
	touchedWall = false;

	collider->SetPos(position.x + 1, position.y + 2);
}

void Enemy_Barrel::ChangeState(Barrel_State prevState, Barrel_State newState)
{
	switch (newState)
	{
	case BARREL_MOVING:
		if (prevState == BARREL_FALLING)
		{
			direction *= -1;
		}
		currentAnim = &BarrelAnim;

		break;

	case BARREL_FALLING:
		position.x = aux.x - 4;
		currentAnim = &BarrelFall;

		break;

	default:
		break;
	}
}

void Enemy_Barrel::OnCollision(Collider* c1, Collider* c2)
{
	//Rolling on the floor collisions
	if (c1 == collider && c2->type == Collider::Type::RAMP_RIGHT)
	{
		rampRight = true;
		aux = c2->GetRect();
	}

	if (c1 == collider && c2->type == Collider::Type::RAMP_LEFT)
	{
		rampLeft = true;
		aux = c2->GetRect();
	}


	//Going down stairs collisions
	if (c1 == collider && c2->type == Collider::Type::TOP_STAIR)
	{
		canGoDownStairs = true;
		aux = c2->GetRect();
	}

	if (c1 == collider && c2->type == Collider::Type::WALL)
	{
		touchedWall = true;
	}

}