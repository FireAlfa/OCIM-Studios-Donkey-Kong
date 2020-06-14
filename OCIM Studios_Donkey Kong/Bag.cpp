#include "Application.h"
#include "ModuleCollisions.h"
#include "Bag.h"

Bag::Bag(int x, int y) : Object(x, y)
{
	bagAnim.PushBack({ 17, 0, 8, 12 });

	currentAnim = &bagAnim;
	objcollider = App->collisions->AddCollider({4, 6, 8, 12}, Collider::Type::OBJECT, (Module*)App->objects);
}

void Bag::Update()
{
	Object::Update();
}