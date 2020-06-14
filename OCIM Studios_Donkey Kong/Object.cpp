#include "Object.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"



Object::Object(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Object::~Object()
{
	if (objcollider != nullptr)
		objcollider->pendingToDelete = true;
}

const Collider* Object::GetCollider() const
{
	return objcollider;
}

void Object::Update()
{
	if (objcollider != nullptr)
	{
		objcollider->SetPos(position.x, position.y);
	}
}

void Object::Draw()
{
	/*if (currentAnim != nullptr)
	{
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame));
	}*/
}

void Object::OnCollision(Collider* c1, Collider* c2)
{

	SetToDelete();
}

void Object::SetToDelete()
{
	pendingToDelete = true;
	if (objcollider != nullptr)
		objcollider->pendingToDelete = true;
}