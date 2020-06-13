#ifndef __SCENE_LVL1_H__
#define __SCENE_LVL1_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel1 : public Module
{
public:
	//Constructor
	SceneLevel1(bool startEnabled);

	//Destructor
	~SceneLevel1();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update();

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate();

	// Disables the player and the enemies
	bool CleanUp();

public:

	//
	//Texture variables
	//
		SDL_Texture* lvl1Texture = nullptr;
		SDL_Texture* lvl1Barrels = nullptr;
	//
	//
	//
	//Collider arrays
	//
	//
	//
	Collider* ladderColliders[4];

	SDL_Texture* dkBarrels;
	Animation DK;
	
	//
	//Srite rectangles
	//
	SDL_Rect lvl1Rect;
	SDL_Rect Barrels;
	//SDL_Rect lvl1B;

	//SDL_Rect buttonRect;


	//Button array

};

#endif