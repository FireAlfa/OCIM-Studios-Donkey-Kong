#include "SceneLevel1.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

#include "ModuleEnemies.h"
#include "ModulePlayer.h"


SceneLevel1::SceneLevel1(bool startEnabled) : Module(startEnabled)
{
	name = "level_1";


	//
	//Set position for textures
	//
	lvl1Rect = { 0, 0, 224, 256 };
	Barrels.PushBack({});


	//
	//
	//
	//Scene 1 Animation pushbacks
	//
	//
	//
}

SceneLevel1::~SceneLevel1()
{

}

// Load assets
bool SceneLevel1::Start()
{
	LOG("Loading Level 1 assets--------\n");

	bool ret = true;



	//Enable modules
	App->player->Enable();
	App->enemies->Enable();
	App->collisions->Enable();


	//
	//Load the files of each texture & audio
	//
	lvl1Texture = App->textures->Load("Assets/Maps/level1.png");
	lvl1Barrels = App->textures->Load("Assets/Sprites/Barrells_Sprites");


	// ===================== GODOWNWALLS ==================== //


	App->collisions->AddCollider({ 160, 222, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 144, 221, 16, 4 }, Collider::Type::GODOWNWALL);

	App->collisions->AddCollider({ 32, 190, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 48, 189, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 64, 188, 16, 4 }, Collider::Type::GODOWNWALL);

	App->collisions->AddCollider({ 176, 157, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 160, 156, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 144, 155, 16, 4 }, Collider::Type::GODOWNWALL);

	App->collisions->AddCollider({ 32, 124, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 48, 123, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 64, 122, 16, 4 }, Collider::Type::GODOWNWALL);

	App->collisions->AddCollider({ 192, 92, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 176, 91, 16, 4 }, Collider::Type::GODOWNWALL);
	App->collisions->AddCollider({ 160, 90, 16, 4 }, Collider::Type::GODOWNWALL);

// ===================== WALLS ==================== //

		//Floor 1 colliders
	App->collisions->AddCollider({ 0, 248, 112, 4 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 247, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 246, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 245, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 244, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 243, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 192, 242, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 208, 241, 16, 4 }, Collider::Type::GOUPWALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 192, 220, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 219, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 218, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 217, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 216, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 112, 215, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 96, 214, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 80, 213, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 64, 212, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 48, 211, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 32, 210, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 16, 209, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 0, 208, 16, 2}, Collider::Type::GOUPWALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 16, 187, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 32, 186, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 48, 185, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 64, 184, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 80, 183, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 96, 182, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 112, 181, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 180, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 179, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 178, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 177, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 192, 176, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 208, 175, 16, 4 }, Collider::Type::GOUPWALL);

	//Floor 4 colliders
	App->collisions->AddCollider({ 192, 154, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 153, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 152, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 151, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 150, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 112, 149, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 96, 148, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 80, 147, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 64, 146, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 48, 145, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 32, 144, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 16, 143, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 0, 142, 16, 4 }, Collider::Type::GOUPWALL);

	//Floor 5 colliders
	App->collisions->AddCollider({ 16, 121, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 32, 120, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 48, 119, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 64, 118, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 80, 117, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 96, 116, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 112, 115, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 114, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 113, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 112, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 111, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 192, 110, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 208, 109, 16, 4 }, Collider::Type::GOUPWALL);

	//Floor 6 colliders
	App->collisions->AddCollider({ 192, 88, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 87, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 86, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 85, 16, 4 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 0, 84, 144, 4 }, Collider::Type::WALL);

	//Floor 7 colliders
	App->collisions->AddCollider({ 88, 56, 48, 8 }, Collider::Type::WALL);

	/*
	// ================== STAIR ================= //
	
		// Stairs set 1
	App->collisions->AddCollider({ 187, 219, 2, 19 }, Collider::Type::STAIR);


	// Stairs set 2
	App->collisions->AddCollider({ 99, 182, 2, 23 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 186, 2, 16 }, Collider::Type::STAIR);

	// Stairs set 3
	App->collisions->AddCollider({ 115, 149, 2, 21 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 153, 2, 17 }, Collider::Type::STAIR);

	// Stairs set 4
	App->collisions->AddCollider({ 75,118, 2, 19 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 120, 2, 19 }, Collider::Type::STAIR);

	// Stairs set 5
	App->collisions->AddCollider({ 187,87, 2, 15 }, Collider::Type::STAIR);

	// Stairs set 6
	App->collisions->AddCollider({ 131,56, 2, 18 }, Collider::Type::STAIR);

	*/

	// ===================== GRAVITY WALLS ==================== //

	/*
		//Gravity Walls 1
	App->collisions->AddCollider({ 211, 202, 14, 18 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 2
	App->collisions->AddCollider({ 0, 169, 14, 18 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 3
	App->collisions->AddCollider({ 211, 136, 14, 18 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 4
	App->collisions->AddCollider({ 0, 104, 13, 18 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 5
	App->collisions->AddCollider({ 211, 70, 13, 18 }, Collider::Type::GRAVITYWALLS);

	   */

	// ================== Border Walls ================ //

		//TOP WALL
	App->collisions->AddCollider({ 0, 0, 224, 5 }, Collider::Type::TOPWALL);
	//LEFT WALL
	App->collisions->AddCollider({ 0, 0, 2, 256 }, Collider::Type::LEFTWALL);
	//RIGHT WALL
	App->collisions->AddCollider({ 223, 1, 1, 255 }, Collider::Type::RIGHTWALL);

	//
	//Add enemies
	//

	

	return ret;
}

//Draw the animations
Update_Status SceneLevel1::Update()
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
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}

	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 90);
	}

	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel4, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}


// Update: draw background
Update_Status SceneLevel1::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//Draw the background
	//
	App->render->Blit(lvl1Texture, 0, 0, &lvl1Rect, NULL, false);


	return Update_Status::UPDATE_CONTINUE;
}

//Disable modules related to the Scene
bool SceneLevel1::CleanUp()
{
	//Disable modules
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();


	return true;
}