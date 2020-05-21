#ifndef __MODULERENDERER_H__
#define __MODULERENDERER_H__

#include "Module.h"

struct SDL_Rect;
struct SDL_Texture;
struct SDL_Renderer;

//RenderClass
class ModuleRender : public Module
{
public:

	ModuleRender();

	~ModuleRender();


	// Called on application start.
	// Creates the rendering context using the program's window.
	bool Init() override;

	// Called at the end of the application loop.
	// Displays a rectangle in the rendering context
	// Updates the screen with the rendered content
	update_status PostUpdate() override;

	// Called on application exit.
	// Destroys the rendering context
	bool CleanUp() override;

	// Prints a texture to the rendering context.
	// Param texture	- A valid SDL Texture, validation checks are not performed
	// Param x,y		- Position x,y in the screen (upper left axis)
	// Param section	- The portion of the texture we want to copy. nullptr for the entire texture
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section = nullptr);


public:
	// Rendering context used for any rendering action
	SDL_Renderer* renderer = nullptr;

private:
	SDL_Texture* testTexture = nullptr;

};

#endif //__ModuleRenderer_H__