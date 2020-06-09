#include "ModuleTextures.h"

#include "Application.h"
#include "ModuleRender.h"

#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

ModuleTextures::ModuleTextures(bool startEnabled) : Module(startEnabled)
{
	// TODO 5: Initialize all texture pointers to nullptr
	for (uint i = 0; i < MAX_TEXTURES; ++i)
		textures[i] = nullptr;
}

ModuleTextures::~ModuleTextures()
{}

bool ModuleTextures::Init()
{
	LOG("Init Image library--------\n");
	bool ret = true;

	// Load support for the PNG image format
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	// Check if all flags were initialized correctly
	if ((init & flags) != flags)
	{
		LOG("Could not initialize Image lib. IMG_Init: %s", IMG_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleTextures::CleanUp()
{
	LOG("Freeing textures and Image library--------\n");

	// TODO 6: Free all textures
	for (uint i = 0; i < MAX_TEXTURES; ++i)
	{
		if (textures[i] != nullptr)
		{
			SDL_DestroyTexture(textures[i]);
			textures[i] = nullptr;
		}
	}

	IMG_Quit();
	return true;
}

//Load a texture
SDL_Texture* const ModuleTextures::Load(const char* path)
{

	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = IMG_Load(path);

	if (surface == NULL)
	{
		LOG("Could not load surface with path: %s. IMG_Load: %s", path, IMG_GetError());
	}
	else
	{
		// TODO 3: Once your have the surface, create a texture from it (check for errors again)
		texture = SDL_CreateTextureFromSurface(App->render->renderer, surface);

		if (texture == NULL)
		{
			LOG("Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			// TODO 4:	Remember to free the surface at the end
			//			Add the texture to our own array so we can properly free all textures on application exit
			for (uint i = 0; i < MAX_TEXTURES; ++i)
			{
				if (textures[i] == nullptr)
				{
					textures[i] = texture;
					break;
				}
			}
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

//Unload a texture
bool ModuleTextures::Unload(SDL_Texture* texture)
{
	bool ret = false;

	if (texture != nullptr)
	{
		for (int i = 0; i < MAX_TEXTURES; ++i)
		{
			if (textures[i] == texture)
			{
				textures[i] = nullptr;
				ret = true;
				break;
			}
		}
		SDL_DestroyTexture(texture);
	}

	return ret;
}