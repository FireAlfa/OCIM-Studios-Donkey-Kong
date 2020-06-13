#ifndef __ENEMY_FIRE_H__
#define __ENEMY_FIRE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Fire : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Fire(int x, int y, int direction);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	SDL_Texture* Texture = nullptr;

	// The path that will define the position in the world
	Path path;

	// Enemy animations
	Animation Fire, back;
};

#endif // __ENEMY_DONKEYKONG_H__