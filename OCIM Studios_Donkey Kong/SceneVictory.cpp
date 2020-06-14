#include "SceneVictory.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"


SceneVictory::SceneVictory(bool startEnabled) : Module(startEnabled)
{
	name = "s_victory";

}

SceneVictory::~SceneVictory()
{

}

// Load assets
bool SceneVictory::Start()
{
	LOG("Loading SceneVictory assets ---------\n");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Maps/victoryScreen.png");

	//
	//
	//
	//Play start music
	//
	//
	//



	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneVictory::Update()
{
	//Gamepad support
	GamePad& pad = App->input->pads[0];


	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN || pad.a == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 60);
	}

	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 10);
	}

	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 10);
	}

	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 10);
	}


	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneVictory::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);


	return Update_Status::UPDATE_CONTINUE;
}