#include "ModuleRender.h"

#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"

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

	//VSYNC flag
	if (VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

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


// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect{ x, y, 0, 0 };

	if (section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		//Collect the texture size into rect.w and rect.h variables
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	}

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}