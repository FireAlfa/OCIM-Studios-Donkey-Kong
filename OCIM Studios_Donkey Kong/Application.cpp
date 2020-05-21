#include "Application.h"

#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"

//Allocates memory for each module in the Modules Array
Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	modules[0] = window = new ModuleWindow();
	modules[1] = input = new ModuleInput();
	modules[2] = textures = new ModuleTextures();
	modules[1] = render = new ModuleRender();
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
	//Init() every module in the Modules Array
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		modules[i]->Init();
	}

	return true;
}

//Update each module in the Modules Array and returns if there's an error
update_status Application::Update()
{
	//Error control
	update_status ret = update_status::UPDATE_CONTINUE;

	//Calls the PreUpdates in the Module Array and stops if there's an error
	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->PreUpdate();

	//Calls the Updates in the Module Array and stops if there's an error
	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->Update();

	//Calls the PostUpdates in the Module Array and stops if there's an error
	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
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