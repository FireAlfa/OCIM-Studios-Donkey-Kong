#include "SceneLevel2.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

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
	App->collisions->Enable();

	//
	//Load the files of each texture & audio
	//
	lvl2Texture = App->textures->Load("Assets/Maps/level2.png");


	princessTexture = App->textures->Load("Assets/Sprites/Peach_Sprites.png");


	//
	//Place colliders
	//
	//Floor 0 colliders
	App->collisions->AddCollider({ 0, 248, 227, 1 }, Collider::Type::WALL);

	//Floor 1 colliders
	App->collisions->AddCollider({ 8, 208, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 208, 48, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 88, 208, 48, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 208, 48, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 200, 208, 15, 1 }, Collider::Type::WALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 8, 168, 40, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 72, 168, 72, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 168, 48, 1 }, Collider::Type::WALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 0, 128, 24, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 128, 48, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 88, 128, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 128, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 128, 48, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 200, 128, 24, 1 }, Collider::Type::WALL);


	//Floor 4 colliders
	App->collisions->AddCollider({ 8, 88, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 24, 88, 176, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 208, 88, 8, 1 }, Collider::Type::WALL);




	//Stairs Set 1
	//App->collisions->AddCollider({ 11, 208, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 27, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 27, 207, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 83, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 83, 207, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 139, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 139, 207, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 195, 223, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 195, 207, 2, 2 }, Collider::Type::TOP_STAIR);

	//Stairs Set 2
	App->collisions->AddCollider({ 67, 183, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 67, 167, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 147, 183, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 147, 167, 2, 2 }, Collider::Type::TOP_STAIR);

	//Stairs Set 3
	App->collisions->AddCollider({ 27, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 27, 127, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 83, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 83, 127, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 139, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 139, 127, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 195, 143, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 195, 127, 2, 2 }, Collider::Type::TOP_STAIR);

	//Stairs Set 4
	App->collisions->AddCollider({ 19, 103, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 19, 87, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 203, 103, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 203, 87, 2, 2 }, Collider::Type::TOP_STAIR);



	//Gravity Walls 1
	App->collisions->AddCollider({ 0, 207, 5, 5 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 219, 207, 5, 5 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 2
	App->collisions->AddCollider({ 0, 167, 5, 5 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 51, 167, 10, 5 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 155, 167, 10, 5 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 219, 167, 5, 5 }, Collider::Type::GRAVITYWALLS);


	//Gravity Walls 3
	App->collisions->AddCollider({ 101, 113, 23, 18 }, Collider::Type::GRAVITYWALLS);


	//Gravity Walls 4
	App->collisions->AddCollider({ 0, 87, 5, 5 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 219, 87, 5, 5 }, Collider::Type::GRAVITYWALLS);


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
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 10);
	}

	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel1, 10);
	}

	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 10);
	}
	if (App->input->keys[SDL_SCANCODE_R] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, this, 10);
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
	App->collisions->Disable();

	return true;
}