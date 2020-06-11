#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

//Different states of the player
enum Player_State
{
	IDLE,
	RUNNING,
	JUMPING,
	HAMMER_IDLE,
	HAMMER_RUNNING,
	HAMMER_JUMPING,
	CLIMBING,
};


//Player Class
class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool startEnabled);

	// Destructor
	~ModulePlayer();


	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	Update_Status Update() override;

	// Checks for inputs (or timers) and changes the player state accordingly
	void UpdateState();

	// Updates the logic of the player depending on the current state
	void UpdateLogic();

	// Transition from one state to a new one. Changes animations, resets variables,...
	void ChangeState(Player_State previousState, Player_State newState);

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	Update_Status PostUpdate() override;


	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	// Draws gamepad debug info in the screen
	void DebugDrawGamepadInfo();

public:

	//
	//Variables ralated to the player
	//

	// Position of the player in the map
	iPoint position;
	
	// The state of the player
	Player_State state = IDLE;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* playerTexture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	//The Player's collider
	Collider* collider = nullptr;


	// The speed in which we move the player (pixels per frame)
	int speed = 1;

	// The direction where the player is facing -> -1 for Left // 1 for Right
	int facingDirection = 1;

	//If player is climbing up or down -> -1 for Down // 1 for Up
	int upDownDirection = 1;

	// Jump handlers
	uint jumpCountdown = 30;
	int jumpDirection = 1;


	///////ANIMATION SETS////////
	Animation idleAnim_Left;
	Animation idleAnim_Right;

	Animation runningAnim_Left;
	Animation runningAnim_Right;

	Animation jumpAnim_Left;
	Animation jumpAnim_Right;

	//Animation climbAnim;
	Animation climb_Up;
	Animation climb_Down;

	Animation hammerIdleAnim_Left;
	Animation hammerIdleAnim_Right;

	Animation hammerRunAnim_Left;
	Animation hammerRunAnim_Right;
	//////////////////////////////////////


	//A flag to detect when the player has been destroyed
	bool destroyed = false;

	// Flag set when the player is near a ladder
	bool canClimb = false;




	// Sound effects indices
	uint jumpFx = 0;

	// Font score index
	uint score = 000;
	int scoreFont = -1;
	char scoreText[10] = { "\0" };

	// Debug flag for gamepad data drawing
	bool debugGamepadInfo = false;
};

#endif //!__MODULE_PLAYER_H__