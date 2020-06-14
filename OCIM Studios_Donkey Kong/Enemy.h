#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "ModuleEnemies.h"
#include <time.h>

struct SDL_Texture;
struct Collider;


//Enemy base class
class Enemy
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Enemy(int x, int y);
	// Destructor
	virtual ~Enemy();

	// Returns the enemy's collider
	const Collider* GetCollider() const;

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Collision response
	// Triggers an animation and a sound fx
	virtual void OnCollision(Collider* c1, Collider* c2);

	// Sets flag for deletion and for the collider aswell
	virtual void SetToDelete();

public:

	//Position of the enemy in the map
	iPoint position;

	int speed = 1;

	//Facing Diretion of the enemy
	int facingDirection = 1;

	//Rectangle of other collider
	SDL_Rect aux;

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	// Sound fx when destroyed
	int destroyedFx = 0;

	// A flag for the enemy removal. Important! We do not delete objects instantly
	bool pendingToDelete = false;

	//collision flag
	bool enemyCanFall = false;
	bool enemyHitRight = false;
	bool enemyHitLeft = false;

	//Var to allocate rand value
	int randomValue;

protected:
	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	// The enemy's collider
	Collider* collider = nullptr;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPos;
};

#endif // __ENEMY_H__