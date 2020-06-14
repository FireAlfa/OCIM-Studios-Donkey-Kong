#include "ModuleObject.h"

#include "Application.h"
#include "Globals.h"

#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

//
//Include objts.h
//
#include "Object.h"
#include "Bag.h"


ModuleObject::ModuleObject(bool startEnabled) : Module(startEnabled)
{
	name = "objects";

	for (uint i = 0; i < MAX_OBJ; ++i)
		objects[i] = nullptr;
}

ModuleObject::~ModuleObject()
{

}



//Called when the module is activated
//By now we will consider all modules to be permanently active
bool ModuleObject::Start()
{
	//
	//Load texture files used by ALL objects
	//
	objTexture = App->textures->Load("Assets/GUI/PickUps_Sprites.png");


	//
	//Load FX files used by ALL enemies
	//
	objectPickedFx = App->audio->LoadFx("Assets/Audio/FX/itemget.ogg"); //General enemy death sound

	return true;
}



// Called at the beginning of the application loop
// Removes all particles pending to delete
Update_Status ModuleObject::PreUpdate()
{
	// Remove all objects scheduled for deletion
	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] != nullptr && objects[i]->pendingToDelete)
		{
			delete objects[i];
			objects[i] = nullptr;
		}
	}
	return Update_Status::UPDATE_CONTINUE;
}

// Called at the middle of the application loop
// Iterates all the particles and calls its Update()
// Removes any "dead" particles
Update_Status ModuleObject::Update()
{
	HandleObjectSpawn();

	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] != nullptr)
			objects[i]->Update();
	}

	HandleObjectDespawn();

	return Update_Status::UPDATE_CONTINUE;
}

// Called at the end of the application loop
// Iterates all the particles and draws them
Update_Status ModuleObject::PostUpdate()
{
	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] != nullptr)
			objects[i]->Draw();
	}

	return Update_Status::UPDATE_CONTINUE;
}

//Called at the end of the application
bool ModuleObject::CleanUp()
{
	LOG("Freeing all objects");

	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] != nullptr)
		{
			delete objects[i];
			objects[i] = nullptr;
		}
	}

	return true;
}

//Add an object to the queue
bool ModuleObject::AddObject(ObjectType type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (spawnQueue[i].Type == ObjectType::NO_TYPE)
		{
			spawnQueue[i].Type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

//Controls the objects spawn
void ModuleObject::HandleObjectSpawn()
{
	// Iterate all the objects queue
	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (spawnQueue[i].Type != ObjectType::NO_TYPE)
		{
				SpawnObject(spawnQueue[i]);
				spawnQueue[i].Type = ObjectType::NO_TYPE; // Removing the newly spawned object from the queue
			
		}
	}
}


//Control the objects despawn
void ModuleObject::HandleObjectDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] != nullptr)
		{
				delete objects[i];
				objects[i] = nullptr;
		}
	}
}

void ModuleObject::SpawnObject(const ObjectSpawnPoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] == nullptr)
		{
			switch (info.Type)
			{
			case ObjectType::BAG:
				objects[i] = new Bag(info.x, info.y);

				break;
			
				//TODO obj cases

			}
			objects[i]->texture = objTexture;
			objects[i]->pickedFx = objectPickedFx;
			break;
		}
	}
}



void ModuleObject::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_OBJ; ++i)
	{
		if (objects[i] != nullptr && objects[i]->GetCollider() == c1)
		{
			objects[i]->OnCollision(c1); //Notify the object of a collision

			//delete [i];
			//enemies[i] = nullptr;
			break;
		}
	}
}