#include "Enemy_Barrel.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

Enemy_Barrel::Enemy_Barrel(int x, int y) : Enemy(x, y)
{
	//	================ BarrelRight =============	//
	BarrelRight.PushBack({ 32, 0, 12, 10 });
	BarrelRight.PushBack({ 45, 0, 12, 10 });
	BarrelRight.PushBack({ 58, 0, 12, 10 });
	BarrelRight.PushBack({ 71, 0, 12, 10 });

	BarrelRight.speed = 0.03f;
	BarrelRight.loop = true;
	currentAnim = &BarrelRight;

	// ================ BarrelLeft ================== //
	
	BarrelLeft.PushBack({ 71, 0, 12, 10 });
	BarrelLeft.PushBack({ 45, 0, 12, 10 });
	BarrelLeft.PushBack({ 58, 0, 12, 10 });
	BarrelLeft.PushBack({ 32, 0, 12, 10 });

	BarrelLeft.speed = 0.03f;
	BarrelLeft.loop = true;
	currentAnim = &BarrelLeft;

	// ================ BarrelDown ================== //	
	BarrelDown.PushBack({ 21, 17, 16, 11 });
	BarrelDown.PushBack({ 38, 17, 16, 10 });

	BarrelLeft.speed = 0.01f;
	BarrelDown.loop = true;
	currentAnim = &BarrelDown;
	





	LeftbarrelPath.PushBack({ 0.3f, 0.0 }, 20, &BarrelLeft);
	RightbarrelPath.PushBack({ -0.3f, 0.0 }, 20, &BarrelRight);
	DownbarrelPath.PushBack({ -0.3f, 0.0 }, 20, &BarrelDown);
	





	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);

}

void Enemy_Barrel::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position

	
	LeftbarrelPath.Update();
	RightbarrelPath.Update();
	DownbarrelPath.Update();
	LeftbarrelPathposition = spawnPos +


	Enemy::Update();
}