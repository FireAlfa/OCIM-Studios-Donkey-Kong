#include "Enemy_DonkeyKong.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"

Enemy_DonkeyKong::Enemy_DonkeyKong(int x, int y) : Enemy(x, y)
{
	texture = App->textures->Load("Assets/Sprites/DonkeyKong_Sprites.png");

	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 217, 0, 46, 32 });
	DonkeyKong.PushBack({ 170, 0, 46, 32 });
	DonkeyKong.pingpong = true;
	DonkeyKong.loop = true;
	DonkeyKong.speed = 0.1f;

	//path.PushBack({ -0.3f, 0.0f }, 150, &DonkeyKong);
	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

Enemy_DonkeyKong::~Enemy_DonkeyKong() {
	collider->pendingToDelete = true;
}

void Enemy_DonkeyKong::Update()
{
	//path.Update();
	//position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}