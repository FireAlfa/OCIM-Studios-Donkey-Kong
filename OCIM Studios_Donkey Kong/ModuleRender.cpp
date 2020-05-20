#include "ModuleRender.h"

#include "Application.h"
#include "ModuleWindow.h"
#include "Application.h"

#include "SDL/include/SDL.h"

//Constructor
ModuleRender::ModuleRender()
{

}

//Destructor
ModuleRender::~ModuleRender()
{

}


//Initiate the Render
bool ModuleRender::Init()
{
	LOG("Creating Renderer context--------------\n");
	bool ret = true;
	Uint32 flags = 0;

	//Sets the renderer to be window size
	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	//Error control
	if (renderer == nullptr)
	{
		LOG("----- Renderer could not be created! SDL_Error: \n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		LOG("Renderer created succesfully--------------\n");
	}

	return ret;
}

//Paints the render on screen
update_status ModuleRender::PostUpdate()
{
	//Square with the Screen Size
	SDL_Rect screenRect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Select the color to use in the next render
	SDL_SetRenderDrawColor(renderer, 190, 0, 0, 255);
	//Render a rectangle in the screen
	SDL_RenderFillRect(renderer, &screenRect);

	//Update screen with renderer content
	SDL_RenderPresent(renderer);

	return update_status::UPDATE_CONTINUE;
}

//Destroys the render subsystem
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy the rendering context
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}