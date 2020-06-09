#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"

#include "SDL/include/SDL_scancode.h"

// Street Fighter reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	//
	//
	//
	//Animation pushbacks
	//
	//
	//
}

ModulePlayer::~ModulePlayer()
{

}

//Load the player textures
bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;
	
	//
	//
	//
	//Set initial position
	//
	//
	//

	//
	//
	//
	//Load Player textures files
	//
	//
	//

	return ret;
}

update_status ModulePlayer::Update()
{
	//
	//
	//
	//Call the updates
	//
	//
	//

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(playerTexture, position.x, position.y, &rect);
	}

	return update_status::UPDATE_CONTINUE;
}