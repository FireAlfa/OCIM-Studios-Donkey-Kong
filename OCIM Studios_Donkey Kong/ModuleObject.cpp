#include "ModuleObject.h"

#include "Application.h"
#include "Globals.h"


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

	return true;
}



// Called at the beginning of the application loop
// Removes all particles pending to delete
Update_Status ModuleObject::PreUpdate()
{

	return Update_Status::UPDATE_CONTINUE;
}

// Called at the middle of the application loop
// Iterates all the particles and calls its Update()
// Removes any "dead" particles
Update_Status ModuleObject::Update()
{

	return Update_Status::UPDATE_CONTINUE;
}

// Called at the end of the application loop
// Iterates all the particles and draws them
Update_Status ModuleObject::PostUpdate()
{

	return Update_Status::UPDATE_CONTINUE;
}

//Called at the end of the application
bool ModuleObject::CleanUp()
{

	return true;
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