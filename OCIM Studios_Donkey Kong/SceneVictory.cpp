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
	vscreen = { 0, 0, 224, 256 };
	wincond = { 0, 0, 224, 256 };
	goDown = { 94,103 ,40,32 };
	Mario = { 51,17,12,16 };
	Peach = { 33,0,14,22 };
	heart = { 0,17,15,13 };




	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
	armS.PushBack({ 170,0,46,32 });
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
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });
	armS.PushBack({ 217,0,46,32 });

	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });
	landr.PushBack({ 134,103,47,27 });


	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });
	landr.PushBack({ 182,103,46,29 });


	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });
	landr.PushBack({ 47,103,47,27 });


	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });
	landr.PushBack({ 0,103,46,29 });

}

SceneVictory::~SceneVictory()
{

}

// Load assets
bool SceneVictory::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	lvl1Texture = App->textures->Load("Assets/Maps/victoryScreen.png");
	peachT = App->textures->Load("Assets/Sprites/Peach_Sprites.png");
	marioT = App->textures->Load("Assets/Sprites/Mario_Sprites.png");
	heartVicotry = App->textures->Load("Assets/Maps/victoryScreen2.png");
	deathanim = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");
	downAnim = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");
	leftright = App->textures->Load("Assets/Sprites/Enemies_Sprites.png");
	heartT = App->textures->Load("Assets/GUI/Particles.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneVictory::Update()
{

	GamePad& pad = App->input->pads[0];

	armS.Update();
	landr.Update();
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

	counter1++;
	goDownCounter1++;

	if (counter1 % 10 == 0)
	{
		counter2++;
	}

	if (counter2 >= 30)
	{
		if (goDownCounter1 % 10 == 0)
		{
			goDownCounter2++;
		}
	}




	yDescent = 86 + goDownCounter2 + 10;



	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneVictory::PostUpdate()
{
	if (yDescent < 184)
	{
		dead = false;
	}
	// Draw everything --------------------------------------
	if (dead == false)
	{
		App->render->Blit(lvl1Texture, 0, 0, NULL);
	}


	if (counter2 <= 30)
	{
		App->render->Blit(deathanim, 89, 58, &(armS.GetCurrentFrame()), 0.1f);
	}
	if (counter2 >= 30 && yDescent <= 184)
	{
		App->render->Blit(downAnim, 93, yDescent, &goDown, NULL, false);
	}
	if (yDescent == 184)
	{
		dead = true;
	}
	if (dead)
	{

		App->render->Blit(heartVicotry, 0, 0, NULL);
		App->render->Blit(heartT, 85, 45, &heart, NULL, false);
		App->render->Blit(peachT, 74, 66, &Peach, NULL, false);
		App->render->Blit(marioT, 106, 72, &Mario, NULL, false);
	}

	return Update_Status::UPDATE_CONTINUE;
}
bool SceneVictory::CleanUp()
{



	return true;
}