#include "ModuleCollisions.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_Scancode.h"

//Collisions constructor
ModuleCollisions::ModuleCollisions(bool startEnabled) : Module(startEnabled)
{
	name = "collisions";

	//Init colliders array to nullptr
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;


	//
	//Colliders matrix
	//

	matrix[Collider::Type::WALL][Collider::Type::WALL] = false;
	matrix[Collider::Type::WALL][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::WALL][Collider::Type::PLAYER_CENTER] = true;
	matrix[Collider::Type::WALL][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::WALL][Collider::Type::STAIR] = false;
	matrix[Collider::Type::WALL][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::WALL][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::WALL][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::WALL][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::WALL][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::WALL][Collider::Type::PEACH] = false;
	matrix[Collider::Type::WALL][Collider::Type::DK] = false;

	matrix[Collider::Type::PLAYER][Collider::Type::WALL] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::STAIR] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::TOPWALL] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::LEFTWALL] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::RIGHTWALL] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::GRAVITYWALLS] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::PEACH] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::DK] = false;

	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::WALL] = true;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::STAIR] = true;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::BUTTON] = true;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::GRAVITYWALLS] = true;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::PEACH] = false;
	matrix[Collider::Type::PLAYER_CENTER][Collider::Type::DK] = false;

	matrix[Collider::Type::ENEMY][Collider::Type::WALL] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::STAIR] = false; //They should be able to move up and down stairs
	matrix[Collider::Type::ENEMY][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::PEACH] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::DK] = false;

	matrix[Collider::Type::STAIR][Collider::Type::WALL] = false;
	matrix[Collider::Type::STAIR][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::STAIR][Collider::Type::PLAYER_CENTER] = true;
	matrix[Collider::Type::STAIR][Collider::Type::ENEMY] = false; //They should be able to move up and down stairs
	matrix[Collider::Type::STAIR][Collider::Type::STAIR] = false;
	matrix[Collider::Type::STAIR][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::STAIR][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::STAIR][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::STAIR][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::STAIR][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::STAIR][Collider::Type::PEACH] = false;
	matrix[Collider::Type::STAIR][Collider::Type::DK] = false;

	matrix[Collider::Type::BUTTON][Collider::Type::WALL] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::PLAYER_CENTER] = true;
	matrix[Collider::Type::BUTTON][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::STAIR] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::PEACH] = false;
	matrix[Collider::Type::BUTTON][Collider::Type::DK] = false;

	//Top limit
	matrix[Collider::Type::TOPWALL][Collider::Type::WALL] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::TOPWALL][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::STAIR] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::PEACH] = false;
	matrix[Collider::Type::TOPWALL][Collider::Type::DK] = false;

	//Left limit
	matrix[Collider::Type::LEFTWALL][Collider::Type::WALL] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::LEFTWALL][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::STAIR] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::PEACH] = false;
	matrix[Collider::Type::LEFTWALL][Collider::Type::DK] = false;

	//Right limit
	matrix[Collider::Type::RIGHTWALL][Collider::Type::WALL] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::STAIR] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::PEACH] = false;
	matrix[Collider::Type::RIGHTWALL][Collider::Type::DK] = false;

	//Gravity walls
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::WALL] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::PLAYER_CENTER] = true;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::STAIR] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::PEACH] = false;
	matrix[Collider::Type::GRAVITYWALLS][Collider::Type::DK] = false;

	matrix[Collider::Type::PEACH][Collider::Type::WALL] = true;
	matrix[Collider::Type::PEACH][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PEACH][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::PEACH][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::PEACH][Collider::Type::STAIR] = false;
	matrix[Collider::Type::PEACH][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::PEACH][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::PEACH][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::PEACH][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::PEACH][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::PEACH][Collider::Type::PEACH] = false;
	matrix[Collider::Type::PEACH][Collider::Type::DK] = false;

	matrix[Collider::Type::DK][Collider::Type::WALL] = true;
	matrix[Collider::Type::DK][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::DK][Collider::Type::PLAYER_CENTER] = false;
	matrix[Collider::Type::DK][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::DK][Collider::Type::STAIR] = false;
	matrix[Collider::Type::DK][Collider::Type::BUTTON] = false;
	matrix[Collider::Type::DK][Collider::Type::TOPWALL] = false;
	matrix[Collider::Type::DK][Collider::Type::LEFTWALL] = false;
	matrix[Collider::Type::DK][Collider::Type::RIGHTWALL] = false;
	matrix[Collider::Type::DK][Collider::Type::GRAVITYWALLS] = false;
	matrix[Collider::Type::DK][Collider::Type::PEACH] = false;
	matrix[Collider::Type::DK][Collider::Type::DK] = false;
}

// Destructor
ModuleCollisions::~ModuleCollisions()
{

}

//PreUpdate the collisions
Update_Status ModuleCollisions::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->pendingToDelete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			--colliderCount;
		}
	}

	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (matrix[c1->type][c2->type] && c1->Intersects(c2->rect))
			{
				for (uint i = 0; i < MAX_LISTENERS; ++i)
					if (c1->listeners[i] != nullptr) c1->listeners[i]->OnCollision(c1, c2);

				for (uint i = 0; i < MAX_LISTENERS; ++i)
					if (c2->listeners[i] != nullptr) c2->listeners[i]->OnCollision(c2, c1);
			}
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

//Check if you want to Debug
Update_Status ModuleCollisions::Update()
{
	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	return Update_Status::UPDATE_CONTINUE;
}

//Draw the Debug squares
Update_Status ModuleCollisions::PostUpdate()
{
	if (debug)
		DebugDraw();

	return Update_Status::UPDATE_CONTINUE;
}

//Draw the squares for each collider
void ModuleCollisions::DebugDraw()
{
	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
			//
			//Color of each collider
			//
		case Collider::Type::NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case Collider::Type::WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case Collider::Type::GRAVITYWALLS: // blue
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case Collider::Type::PLAYER_CENTER: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::STAIR: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::TOPWALL: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::LEFTWALL: // magenta
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::RIGHTWALL: // magenta
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
			
		}
	}
}

// Called before quitting
bool ModuleCollisions::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			--colliderCount;
		}
	}

	return true;
}

//Add Collider
Collider* ModuleCollisions::AddCollider(SDL_Rect rect, Collider::Type type, Module* listener)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, listener);
			++colliderCount;
			break;
		}
	}

	return ret;
}

//Remove collider
void ModuleCollisions::RemoveCollider(Collider* collider)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == collider)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			--colliderCount;
		}
	}
}