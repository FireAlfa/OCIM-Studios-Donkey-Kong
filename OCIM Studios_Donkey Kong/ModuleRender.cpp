#include "ModuleRender.h"

#include "Application.h"

#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"

#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_scancode.h"



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

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	//Clear rendering target
	SDL_RenderClear(renderer);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::Update()
{
	//Handle positive vertical movement
	if (App->input->keys[SDL_SCANCODE_UP] == KEY_REPEAT)
		camera.y -= cameraSpeed;

	//Handle negative vertical movement
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_REPEAT)
		camera.y += cameraSpeed;

	// Handle negative horizontal movement of the camera
	if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_REPEAT)
		camera.x -= cameraSpeed;
	if (camera.x < 0) camera.x = 0;

	// Handle positive horizontal movement of the camera
	if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT)
		camera.x += cameraSpeed;
	if (camera.x > 1536) camera.x = 1536;


	return update_status::UPDATE_CONTINUE;
}

//Paints the render on screen
update_status ModuleRender::PostUpdate()
{
	//Update the screen
	SDL_RenderPresent(renderer);

	return update_status::UPDATE_CONTINUE;
}

//Destroys the render subsystem
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer--------\n");

	//Destroy the rendering context
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}


// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed)
{
	bool ret = true;

	SDL_Rect rect{
		(int)(-camera.x * speed) + x * SCREEN_SIZE,
		(int)(-camera.y * speed) + y * SCREEN_SIZE,
		0, 0 };

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

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("----- Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}