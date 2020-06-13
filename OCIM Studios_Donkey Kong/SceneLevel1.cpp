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
	Barrels = { 0,0, 21,32 };


	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	fireBarrel.PushBack({ 10,10,7,13 });
	 


	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });
	fireBarrel.PushBack({ 21,11,7,12 });



	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });
	fireBarrel.PushBack({ 32,9,8,14 });



	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });
	fireBarrel.PushBack({ 43,9,7,14 });

	


	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });
	DK.PushBack({ 0,0,40,32 });



	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });
	DK.PushBack({ 41,0,43,32 });

	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });
	DK.PushBack({ 85,0,40,32 });


	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });
	DK.PushBack({ 126,0,43,32 });


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
	dkBarrels = App->textures->Load("Assets/Sprites/DonkeyKong_Sprites.png");
	lvl1Barrels = App->textures->Load("Assets/Sprites/Barrells_Sprites.png");
	lvl1fireBarrels = App->textures->Load("Assets/Sprites/fire.png");


// ===================== WALLS ==================== //


	//
	//Walls with ramps
	//

	//Floor 1 colliders
	App->collisions->AddCollider({ 0, 248, 112, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 111, 246, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 115, 247, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 127, 245, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 131, 246, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 143, 244, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 147, 245, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 159, 243, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 163, 244, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 175, 242, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 179, 243, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 191, 241, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 195, 242, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 208, 240, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 211, 241, 16, 1 }, Collider::Type::WALL);

	//Floor 2 colliders
	App->collisions->AddCollider({ 192, 220, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 218, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 176, 219, 7, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 217, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 160, 218, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 216, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 144, 217, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 215, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 128, 216, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 214, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 112, 215, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 213, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 96, 214, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 212, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 80, 213, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 208, 219, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 64, 212, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 211, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 48, 211, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 209, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 32, 210, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 208, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 16, 209, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 16, 207, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 0, 208, 13, 1 }, Collider::Type::WALL);


	//Floor 3 colliders
	App->collisions->AddCollider({ 0, 248, 112, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 31, 186, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 19, 187, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 47, 184, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 40, 186, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 63, 183, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 51, 185, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 79, 182, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 67, 184, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 95, 181, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 83, 183, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 111, 180, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 105, 182, 7, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 127, 179, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 105, 182, 7, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 143, 178, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 131, 180, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 159, 177, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 147, 179, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 175, 176, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 163, 178, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 191, 175, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 179, 177, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 207, 174, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 195, 176, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 211, 175, 13, 1 }, Collider::Type::WALL);


	//Floor 4 colliders
	App->collisions->AddCollider({ 192, 154, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 192, 152, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 176, 153, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 151, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 160, 152, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 150, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 144, 151, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 149, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 128, 150, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 128, 148, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 120, 149, 7, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 112, 147, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 96, 148, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 96, 146, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 80, 147, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 145, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 64, 146, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 64, 144, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 48, 145, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 48, 143, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 32, 144, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 32, 142, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 16, 143, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 16, 141, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 0, 142, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 210, 109, 14, 1 }, Collider::Type::WALL);

	//Floor 5 colliders
	App->collisions->AddCollider({ 31, 118, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 19, 121, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 47, 118, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 39, 120, 7, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 63, 117, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 51, 119, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 79, 116, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 64, 118, 8, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 95, 115, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 112, 181, 16, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 111, 114, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 99, 116, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 127, 113, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 115, 115, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 143, 112, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 131, 114, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 159, 111, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 147, 113, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 175, 110, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 163, 112, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 191, 109, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 179, 111, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 207, 108, 1, 1 }, Collider::Type::RAMP_RIGHT);
	App->collisions->AddCollider({ 195, 110, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 211, 175, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 80, 117, 16, 1 }, Collider::Type::WALL);

	//Floor 6 colliders
	App->collisions->AddCollider({ 192, 86, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 192, 88, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 176, 85, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 177, 87, 7, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 160, 84, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 160, 86, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 144, 83, 1, 1 }, Collider::Type::RAMP_LEFT);
	App->collisions->AddCollider({ 144, 85, 13, 1 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 0, 84, 141, 1 }, Collider::Type::WALL);


	//Floor 7 colliders
	App->collisions->AddCollider({ 88, 56, 40, 1 }, Collider::Type::WALL);




	
	// ================== STAIR ================= //

	// Stairs set 1
	App->collisions->AddCollider({ 187, 231, 2, 6 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 217, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 2
	App->collisions->AddCollider({ 99, 195, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 184, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 35, 198, 2, 6 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 99, 180, 2, 2 }, Collider::Type::TOP_STAIR);
	// Stairs set 3

	App->collisions->AddCollider({ 115, 163, 2, 9 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 151, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 187, 165, 2, 6 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 115, 147, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 4
	App->collisions->AddCollider({ 75,132, 2, 7 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 35, 118, 2, 2 }, Collider::Type::TOP_STAIR);
	App->collisions->AddCollider({ 35, 133, 2, 5 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 75, 116, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 5
	App->collisions->AddCollider({ 187, 100, 2, 6 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 187, 85, 2, 2 }, Collider::Type::TOP_STAIR);

	// Stairs set 6
	App->collisions->AddCollider({ 131,68, 2, 10 }, Collider::Type::STAIR);
	App->collisions->AddCollider({ 131, 54, 2, 2 }, Collider::Type::TOP_STAIR);
	

	// ===================== GRAVITY WALLS ==================== //

	
		//Gravity Walls 1
	App->collisions->AddCollider({ 211, 202, 14, 18 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 209, 222, 6, 3 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 2
	App->collisions->AddCollider({ 0, 169, 14, 18 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 8, 188, 6, 3 }, Collider::Type::GRAVITYWALLS);
	//Gravity Walls 3
	App->collisions->AddCollider({ 211, 136, 14, 18 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 211, 156, 6, 3 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 4
	App->collisions->AddCollider({ 0, 104, 13, 18 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 7, 123, 6, 3 }, Collider::Type::GRAVITYWALLS);

	//Gravity Walls 5
	App->collisions->AddCollider({ 211, 70, 13, 18 }, Collider::Type::GRAVITYWALLS);
	App->collisions->AddCollider({ 209, 89, 8, 4 }, Collider::Type::GRAVITYWALLS);

	   

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

	DK.Update();
	fireBarrel.Update();
	//
	//Change Level
	//
	if (App->input->keys[SDL_SCANCODE_0] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 10);
	}

	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel2, 10);
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
Update_Status SceneLevel1::PostUpdate()
{
	// Draw everything --------------------------------------

	//
	//Draw the background
	//
	//App->render->Blit(lvl1Barrels, 2, 55, &lvl1B, NULL, false);
	App->render->Blit(lvl1Texture, 0, 0, &lvl1Rect, NULL, false);
	App->render->Blit(dkBarrels, 21, 52, &(DK.GetCurrentFrame()), 0.1f);
	App->render->Blit(lvl1Barrels, 1, 51, &Barrels,NULL,false);
	App->render->Blit(lvl1fireBarrels, 38, 234, &(fireBarrel.GetCurrentFrame()), 0.1f);

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