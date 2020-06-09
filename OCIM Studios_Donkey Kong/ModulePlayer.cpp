#include "ModulePlayer.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include "ModuleRender.h"


#include "SDL/include/SDL_scancode.h"



ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
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

	//
	//
	//
	//Create Player collider
	//
	//
	//

	//Font
	char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	scoreFont = App->fonts->Load("Assets/Fonts/rtype_font3.png", lookupTable, 2); //change file

	return ret;
}

//Main player Update
Update_Status ModulePlayer::Update()
{
	//
	//
	//
	//Call the updates
	//
	//
	//

	return Update_Status::UPDATE_CONTINUE;
}

//Post Update
Update_Status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		//SDL_Rect rect = currentAnimation->GetCurrentFrame();
		SDL_Rect rect = { 0, 0, 32, 32 };
		App->render->Blit(playerTexture, position.x, position.y, &rect);
	}

	return Update_Status::UPDATE_CONTINUE;
}

//Controls what the player does when it collides with another collider
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	//
	//
	//
	//Collision control
	//
	//
	//
}