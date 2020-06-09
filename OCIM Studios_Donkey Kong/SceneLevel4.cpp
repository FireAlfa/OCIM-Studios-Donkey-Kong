#include "SceneLevel4.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


#include "ModulePlayer.h"


SceneLevel4::SceneLevel4()
{
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

	return ret;
}

//Draw the animations
update_status SceneLevel4::Update()
{
	//
	//
	//
	//Update animations
	//
	//
	//

	return update_status::UPDATE_CONTINUE;
}


// Update: draw background
update_status SceneLevel4::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//
	//
	//Draw the background
	//
	//
	//

	return update_status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel4::CleanUp()
{
	//App->player->Disable();

	return true;
}