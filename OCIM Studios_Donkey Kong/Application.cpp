#include "Application.h"

#include "Module.h"

#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

#include "ModulePlayer.h"
#include "SceneIntro.h"
#include "SceneLevel4.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleRender.h"


//Allocates memory for each module in the Modules Array
Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	modules[0] =	window =		new ModuleWindow(true);
	modules[1] =	input =			new ModuleInput(true);
	modules[2] =	textures =		new ModuleTextures(true);
	modules[3] =	audio =			new ModuleAudio(true);

	modules[4] =	sceneIntro =	new SceneIntro(true);
	modules[5] =	sceneLevel4 =	new SceneLevel4(false);
	modules[6] =	player =		new ModulePlayer(false);
	modules[7] =	particles =		new ModuleParticles(true);
	modules[8] =	enemies =		new ModuleEnemies(false);

	modules[9] =	collisions =	new ModuleCollisions(true);
	modules[10] =	fade =			new ModuleFadeToBlack(true);

	modules[11] =	render =		new ModuleRender(true);
}

//Destructor, frees dynamic memory
Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

// Initialize all modules
bool Application::Init()
{
	bool ret = true;

	//Init all the modules in the Module Array
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->Init();

	// Only active modules will be 'started'
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return true;
}

//Update each module in the Modules Array and returns if there's an error
Update_Status Application::Update()
{
	//Error control
	Update_Status ret = Update_Status::UPDATE_CONTINUE;

	//Calls the PreUpdates in the Module Array and stops if there's an error
	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->PreUpdate();

	//Calls the Updates in the Module Array and stops if there's an error
	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->Update();

	//Calls the PostUpdates in the Module Array and stops if there's an error
	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->PostUpdate();

	//Returns the update status
	return ret;
}

//Deletes dynamic memory of each module in the Module Array
bool Application::CleanUp()
{
	bool ret = true;

	//Calls the Clean Ups in the Module Array and stops if there's an error
	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
	{
		//Error control
		ret = modules[i]->CleanUp();
	}

	//Returns de clean up status
	return ret;
}