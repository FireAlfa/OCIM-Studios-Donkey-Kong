#include "SceneLevel4.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "ModuleEnemies.h"
#include "Enemy_DonkeyKong.h"
#include "ModulePlayer.h"


SceneLevel4::SceneLevel4(bool startEnabled) : Module(startEnabled)
{
	name = "level_4";

	
	//
	//Set position for textures
	//
	lvl4Rect = { 0, 0, 224, 256 };
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

SceneLevel4::~SceneLevel4()
{

}

// Load assets
bool SceneLevel4::Start()
{
	LOG("Loading Level 4 assets--------\n");

	bool ret = true;


	//Enable modules
	App->player->Enable();
	App->enemies->Enable();


	//
	//Load the files of each texture & audio
	//
	lvl4Texture = App->textures->Load("Assets/Maps/level4.png");
	buttonTexture = App->textures->Load("Assets/GUI/Button.png");

	donkeyKongTexture = App->textures->Load("Assets/Sprites/DonkeyKong_Sprites.png");
	princessTexture = App->textures->Load("Assets/Sprites/Peach_Sprites.png");


	//
	//Place colliders
	//
	//Floor 0 colliders
	App->collisions->AddCollider({ 0, 248, 227, 4 }, Collider::Type::WALL);

	//Floor 1 colliders
	App->collisions->AddCollider({ 16, 208, 40, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 208, 39, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 208, 47, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 208, 39, 4 }, Collider::Type::WALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 24, 168, 32, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 168, 7, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 168, 63, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 152, 168, 7, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 168, 31, 4 }, Collider::Type::WALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 32, 128, 24, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 128, 39, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 128, 47, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 128, 24, 4 }, Collider::Type::WALL);

	//Floor 4 colliders
	App->collisions->AddCollider({ 40, 88, 16, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 72, 88, 80, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 168, 88, 16, 4 }, Collider::Type::WALL);



	//Stairs Set 1
	App->collisions->AddCollider({ 11, 208, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 107, 208, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 211, 208, 2, 26 }, Collider::Type::STAIR);

	//Stairs Set 2
	App->collisions->AddCollider({ 19, 168, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 75, 168, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 147, 168, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 203, 168, 2, 26 }, Collider::Type::STAIR);

	//Stairs Set 3
	App->collisions->AddCollider({ 27, 128, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 107, 128, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 195, 128, 2, 26 }, Collider::Type::STAIR);

	//Stairs Set 4
	App->collisions->AddCollider({ 35, 88, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 88, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 67, 88, 2, 26 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 155, 88, 2, 26 }, Collider::Type::STAIR);



	//Buttons Floor 1
	buttonColliders[0] = App->collisions->AddCollider({ 58, 193, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[1] = App->collisions->AddCollider({ 162, 193, 4, 14 }, Collider::Type::BUTTON);

	//Buttons Floor 2
	buttonColliders[2] = App->collisions->AddCollider({ 58, 153, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[3] = App->collisions->AddCollider({ 162, 153, 4, 14 }, Collider::Type::BUTTON);

	//Buttons Floor 3
	buttonColliders[4] = App->collisions->AddCollider({ 58, 113, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[5] = App->collisions->AddCollider({ 162, 113, 4, 14 }, Collider::Type::BUTTON);

	//Buttons Floor 4
	buttonColliders[6] = App->collisions->AddCollider({ 58, 73, 4, 14 }, Collider::Type::BUTTON);
	buttonColliders[7] = App->collisions->AddCollider({ 162, 73, 4, 14 }, Collider::Type::BUTTON);



	//Gravity Walls 1
	App->collisions->AddCollider({ 0, 168, 5, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 218, 168, 5, 40 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 2
	App->collisions->AddCollider({ 0, 128, 13, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 210, 128, 13, 40 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 3
	App->collisions->AddCollider({ 0, 88, 21, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 203, 88, 21, 40 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 4
	App->collisions->AddCollider({ 0, 48, 29, 40 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 195, 48, 29, 40 }, Collider::Type::GRAVITYWALLS);




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
	//Draw the background
	//
	App->render->Blit(lvl4Texture, 0, 0, &lvl4Rect, NULL, false);

	//
	//Draw the buttons
	//
	for (int i = 0; i < 8; ++i)
	{
		if (buttonDrawingArray[0] == true)
		{
			App->render->Blit(buttonTexture, 56, 207, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[1] == true)
		{
			App->render->Blit(buttonTexture, 160, 207, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[2] == true)
		{
			App->render->Blit(buttonTexture, 56, 167, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[3] == true)
		{
			App->render->Blit(buttonTexture, 160, 167, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[4] == true)
		{
			App->render->Blit(buttonTexture, 56, 127, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[5] == true)
		{
			App->render->Blit(buttonTexture, 56, 127, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[6] == true)
		{
			App->render->Blit(buttonTexture, 56, 87, &buttonRect, NULL, false);
		}
		if (buttonDrawingArray[7] == true)
		{
			App->render->Blit(buttonTexture, 160, 87, &buttonRect, NULL, false);
		}
	}


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