#include "SceneLevel4.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "ModuleEnemies.h"
#include "ModulePlayer.h"


SceneLevel4::SceneLevel4(bool startEnabled) : Module(startEnabled)
{
	name = "level_4";

	//
	//
	//
	//Set position for textures
	//
	//
	//

	//
	//
	//
	//Scene 4 Animation pushbacks
	//
	//
	//
}

SceneLevel4::~SceneLevel4()
{

}

// Load assets
bool SceneLevel4::Start()
{
	LOG("Loading Level 4 assets--------\n");

	bool ret = true;


	//
	//
	//
	//Load the files of each texture & audio
	//
	//
	//

	//
	//
	//
	//Place colliders
	//
	//
	//

	//
	//
	//
	//Add enemies
	//
	//
	//


	//Enable modules
	App->player->Enable();
	App->enemies->Enable();

	return ret;
}

//Draw the animations
Update_Status SceneLevel4::Update()
{
	//
	//
	//
	//Update animations
	//
	//
	//

	return Update_Status::UPDATE_CONTINUE;
}


// Update: draw background
Update_Status SceneLevel4::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//
	//
	//Draw the background
	//
	//
	//

	return Update_Status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel4::CleanUp()
{
	//Disable modules
	App->player->Disable();
	App->enemies->Disable();

	//Remove memory leaks
	App->textures->CleanUp();
	App->collisions->CleanUp();

	return true;
}

//??? COMPROVAR
bool SceneLevel4::CanPlayerClimb() const
{
	for (uint i = 0; i < 4; ++i)
	{
		if (App->player->collider->Intersects(ladderColliders[i]->rect))
			return true;
	}
	return false;
}