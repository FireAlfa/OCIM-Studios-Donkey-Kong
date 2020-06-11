#include "SceneLevel2.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

#include "ModuleEnemies.h"
#include "Enemy_DonkeyKong.h"
#include "ModulePlayer.h"


SceneLevel2::SceneLevel2(bool startEnabled) : Module(startEnabled)
{
	name = "level_2";


	//
	//Set position for textures
	//
	lvl2Rect = { 0, 0, 224, 256 };
	buttonRect = { 0, 0, 8, 9 };


	//
	//Scene 4 Animation pushbacks
	//
	/*DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 0, 0, 39, 32 });
	DonkeyKong.PushBack({ 217, 0, 46, 32 });
	DonkeyKong.PushBack({ 170, 0, 46, 32 });
	DonkeyKong.pingpong = true;
	DonkeyKong.loop = true;*/
}

SceneLevel2::~SceneLevel2()
{

}

// Load assets
bool SceneLevel2::Start()
{
	LOG("Loading Level 2 assets--------\n");

	bool ret = true;


	//Enable modules
	App->player->Enable();
	App->enemies->Enable();


	//
	//Load the files of each texture & audio
	//
	lvl2Texture = App->textures->Load("Assets/Maps/level2.png");


	princessTexture = App->textures->Load("Assets/Sprites/Peach_Sprites.png");


	//
	//Place colliders
	//




	//Top Wall
	App->collisions->AddCollider({ 0, 0, 254, 1 }, Collider::Type::TOPWALL);
	//Left Wall
	App->collisions->AddCollider({ 0, 208, 1, 48 }, Collider::Type::LEFTWALL);
	//RightWall
	App->collisions->AddCollider({ 223, 208, 1, 48 }, Collider::Type::RIGHTWALL);




	//
	//Add enemies
	//
	App->enemies->AddEnemy(Enemy_Type::DONKEYKONG, 92, 56);






	return ret;
}

//Draw the animations
Update_Status SceneLevel2::Update()
{
	//
	//
	//
	//Update animations
	//
	//
	//

	//
	//Change Level
	//
	if (App->input->keys[SDL_SCANCODE_0] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}

	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 90);
	}

	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}


// Update: draw background
Update_Status SceneLevel2::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//Draw the background
	//
	App->render->Blit(lvl2Texture, 0, 0, &lvl2Rect, NULL, false);

	


	return Update_Status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel2::CleanUp()
{
	//Disable modules
	App->player->Disable();
	App->enemies->Disable();

	//Remove memory leaks
	App->textures->CleanUp();
	App->collisions->CleanUp();

	return true;
}