#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel4 : public Module
{
public:
	//Constructor
	SceneLevel4(bool startEnabled);

	//Destructor
	~SceneLevel4();

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

	// Check if the player can climb
	bool CanPlayerClimb() const;

public:

	//
	//
	//
	//Texture variables
	//
	//
	//
	/*SDL_Texture* bgTexture = nullptr; <--Example*/

	//
	//
	//
	//Collider arrays
	//
	//
	//
	Collider* ladderColliders[4];

	
};

#endif