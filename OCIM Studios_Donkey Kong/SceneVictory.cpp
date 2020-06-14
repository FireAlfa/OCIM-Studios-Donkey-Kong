#include "SceneVictory.h"


#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

SceneVictory::SceneVictory(bool startEnabled) : Module(startEnabled)
{
	name = "s_sceneVictory";


	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });

	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
}

SceneVictory::~SceneVictory()
{

}

// Load assets
bool SceneVictory::Start()
{
	LOG("Loading background assets");

	bool ret = true;



	//
	//
	//
	//Play start music
	//
	//
	//




	//
	deathanim = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");

	lvl1Texture = App->textures->Load("Assets/Sprites/victoryScreen.png");





	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneVictory::Update()
{

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
	App->render->Blit(deathanim, 89, 58, &(armS.GetCurrentFrame()), 0.1f);



	return Update_Status::UPDATE_CONTINUE;
}
bool SceneVictory::CleanUp()
{



	return true;
}