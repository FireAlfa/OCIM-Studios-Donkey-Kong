#include "Application.h"

#include "Module.h"
#include "Dummy.h"
#include "DummyEsc.h"


//Allocates memory for each module in the Modules Array
Application::Application()
{
	modules[0] = new ModuleDummy();
	modules[1] = new ModuleDummyESC();
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
	// TODO 3: Make sure all modules have a chance to cleanup
	bool ret = true;

	//Calls the Clean Ups in the Module Array and stops if there's an error
	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
	{
		//Error control
		ret = modules[i]->CleanUp();

		delete modules[i];
		modules[i] = nullptr;
	}

	//Returns de clean up status
	return ret;
}