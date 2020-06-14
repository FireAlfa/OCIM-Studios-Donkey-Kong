#include "Enemy.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

//Constructor sets the initial position of enemy
Enemy::Enemy(int x, int y) : position(x, y)
{
	enemState = MOVING;
	spawnPos = position;
	srand(time(NULL));
}

//Destroys enemy collider
Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

//Get the collider from the enemy
const Collider* Enemy::GetCollider() const
{
	return collider;
}

//Update the animation and position of the enemy
void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
}

//Blit the enemy on the screen
void Enemy::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

//Control the collisions between the enemy and other colliders
void Enemy::OnCollision(Collider* c1, Collider* c2)
{
	switch (enemType)
	{
	case BARREL:
		//Ramp right collision
		if (enemState != FALLING) {
			enemState = MOVING;
			if (c1 == collider && c2->type == Collider::Type::RAMP_RIGHT)
			{
				rampRight = true;
				aux = c2->GetRect();
				lastCollider = Collider::Type::RAMP_RIGHT;
			}
			//Ramp left collision
			if (c1 == collider && c2->type == Collider::Type::RAMP_LEFT)
			{
				rampLeft = true;
				aux = c2->GetRect();
				lastCollider = Collider::Type::RAMP_LEFT;
			}
		}
		//Collision with top Stair
		if (c1 == collider && c2->type == Collider::Type::TOP_STAIR)
		{
			randomValue = rand() % 3;
			if (randomValue == 0)
			{
				enemState = FALLING;
			}
			else {
				enemState = MOVING;
			}
		}
		//Map Border Bounce
		if (enemState == MOVING && c1 == collider && c2->type == Collider::Type::RIGHTWALL || Collider::Type::LEFTWALL)
		{
			randomValue = rand() % 2;
			if (randomValue == 0)
			{
				Enemy::facingDirection *= -1;
			}
		}
		break;
	case BLUEBARREL:
		//Ramp right collision
		if (enemState != FALLING) {
			enemState = MOVING;
			if (c1 == collider && c2->type == Collider::Type::RAMP_RIGHT)
			{
				rampRight = true;
				aux = c2->GetRect();
				lastCollider = Collider::Type::RAMP_RIGHT;
			}
			//Ramp left collision
			if (c1 == collider && c2->type == Collider::Type::RAMP_LEFT)
			{
				rampLeft = true;
				aux = c2->GetRect();
				lastCollider = Collider::Type::RAMP_LEFT;
			}
		}
		//Collision with top Stair
		if (c1 == collider && c2->type == Collider::Type::TOP_STAIR)
		{
			randomValue = rand() % 3;
			if (randomValue == 0)
			{
				enemState = FALLING;
			}
			else {
				enemState = MOVING;
			}
		}
		//Map Border Bounce
		if (enemState == MOVING && c1 == collider && c2->type == Collider::Type::RIGHTWALL || Collider::Type::LEFTWALL)
		{
			randomValue = rand() % 2;
			if (randomValue == 0)
			{
				Enemy::facingDirection *= -1;
			}
		}
		break;
	case FIRE:
		//Collision with top Stair
		if (c1 == collider && c2->type == Collider::Type::TOP_STAIR)
		{
			randomValue = rand() % 2;
			if (randomValue == 0)
			{
				enemState = FALLING;
			}
			else {
				enemState = MOVING;
			}
		}
		//End  of platform Collision
		if (enemState == MOVING && c1 == collider && c2->type == Collider::Type::GRAVITYWALLS || Collider::Type::RIGHTWALL || Collider::Type::LEFTWALL) 
		{
			Enemy::facingDirection *= -1;
		}
		//Stair Collision
		if (c1 == collider && c2->type == Collider::Type::STAIR)
		{
			randomValue = rand() % 2;
			if (randomValue == 0)
			{
				enemState = CLIMBING;
			}
			else {
				enemState = MOVING;
			}
		}
		//Ramp right collision
		if (c1 == collider && c2->type == Collider::Type::RAMP_RIGHT)
		{
			rampRight = true;
			aux = c2->GetRect();
			lastCollider = Collider::Type::RAMP_RIGHT;
		}
		//Ramp left collision
		if (c1 == collider && c2->type == Collider::Type::RAMP_LEFT)
		{
			rampLeft = true;
			aux = c2->GetRect();
			lastCollider = Collider::Type::RAMP_LEFT;
		}
		
		break;
	case CEMENT:
		break;
	default:
		break;
	}
}

//Put the enemy in delete queue
void Enemy::SetToDelete()
{
	pendingToDelete = true;
	if (collider != nullptr)
		collider->pendingToDelete = true;
}