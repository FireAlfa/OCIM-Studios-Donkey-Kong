#include "Enemy_Barrel.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int direction) : Enemy(x, y)
{

	
	currentAnim = &BarrelAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Barrel::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}