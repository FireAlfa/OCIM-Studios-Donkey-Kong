#ifndef __SCENE_VICTORY_H__
#define __SCENE_VICTORY_H__

#include "Module.h"
#include "Animation.h"



#define SPACE_BLINK 40

struct SDL_Texture;

//Class for the First screen of the game
class SceneVictory : public Module
{
public:
	//Constructor
	SceneVictory(bool startEnabled);

	//Destructor
	~SceneVictory();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;


public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
};

#endif