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


	//
	//Load the files of each texture & audio
	//
	lvl1Texture = App->textures->Load("Assets/Maps/level1.png");



// ===================== WALLS ==================== //

		//Floor 1 colliders
	App->collisions->AddCollider({ 0, 248, 112, 8 }, Collider::Type::WALL);
		App->collisions->AddCollider({ 112, 247, 16, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 246, 16, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 245, 16, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 244, 16, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 243, 16, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 192, 242, 16, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 208, 241, 16, 8 }, Collider::Type::GOUPWALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 192, 220, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 219, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 218, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 217, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 216, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 215, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 214, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 213, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 212, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 211, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 210, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 16, 209, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 0, 208, 16, 8 }, Collider::Type::WALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 16, 187, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 186, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 185, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 184, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 183, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 182, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 181, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 180, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 179, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 178, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 177, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 176, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 208, 175, 16, 8 }, Collider::Type::WALL);

	//Floor 4 colliders
	App->collisions->AddCollider({ 192, 154, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 153, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 152, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 151, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 150, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 149, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 148, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 147, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 146, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 145, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 144, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 16, 143, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 0, 142, 16, 8 }, Collider::Type::WALL);

	//Floor 5 colliders
	App->collisions->AddCollider({ 16, 121, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 120, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 119, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 118, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 117, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 116, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 115, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 114, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 113, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 112, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 111, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 110, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 208, 109, 16, 8 }, Collider::Type::WALL);

	//Floor 6 colliders
	App->collisions->AddCollider({ 192, 88, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 87, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 86, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 85, 16, 8 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 0, 84, 144, 8 }, Collider::Type::WALL);

	//Floor 7 colliders
	App->collisions->AddCollider({ 88, 56, 48, 8 }, Collider::Type::WALL);

	// ===================== GOUPWALLS =========================== //

	//	FLOOR		1

	/*
	App->collisions->AddCollider({ 111, 248, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 127, 247, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 143, 246, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 159, 245, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 175, 244, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 191, 243, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 207, 242, 1, 8 }, Collider::Type::GOUPWALL);

	//	FLOOR		2
	App->collisions->AddCollider({ 192, 220, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 219, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 218, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 217,1, 8  }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 216, 1, 8}, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 112, 215, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 96, 214, 1, 8}, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 80, 213, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 64, 212, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 48, 211, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 32, 210, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 16, 209, 1, 8 }, Collider::Type::GOUPWALL);

	//Floor 3 colliders
	App->collisions->AddCollider({ 31, 187, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 47, 186, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 63, 185, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 79, 184, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 95, 183, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 111, 182, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 127, 181, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 143, 180, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 159, 179, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 175, 178, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 191, 1177, 1, 8 }, Collider::Type::GOUPWALL);

	//Floor 4 colliders
	App->collisions->AddCollider({ 192, 154,1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 153, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 152, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 151, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 128, 150, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 112, 149, 11, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 96, 148, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 80, 147, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 64, 146, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 48, 145, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 32, 144, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 16, 143, 1, 8 }, Collider::Type::GOUPWALL);

	//Floor 5 colliders
	App->collisions->AddCollider({ 31, 121,1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 47, 120, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 63, 119, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 79, 118, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 95, 117, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 111, 116, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 127, 115, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 143, 114, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 159, 113, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 175, 112, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 191, 111, 1, 8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 207, 110, 1, 8 }, Collider::Type::GOUPWALL);

	//Floor 6 colliders
	App->collisions->AddCollider({ 192, 88, 1,8}, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 176, 87, 1,8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 160, 86, 1,8 }, Collider::Type::GOUPWALL);
	App->collisions->AddCollider({ 144, 85, 1,8 }, Collider::Type::GOUPWALL);
	*/


	// ================== STAIR ================= //
	/*
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




	// ================== Border Walls ================ //

		//TOP WALL
	App->collisions->AddCollider({ 0, 0, 224, 5 }, Collider::Type::TOPWALL);
	//LEFT WALL
	App->collisions->AddCollider({ 0, 250, 1, 2 }, Collider::Type::LEFTWALL);
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


	return true;
}