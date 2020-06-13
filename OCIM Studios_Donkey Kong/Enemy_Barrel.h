
#ifndef __ENEMY_BARREL_H__
#define __ENEMY_BARREL_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Barrel : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Barrel(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	SDL_Texture* barrelTexture = nullptr;

	// The path that will define the position in the world
	Path LeftbarrelPath;
	Path RightbarrelPath;
	Path DownbarrelPath;
	// Enemy animations
	Animation BarrelRight, BarrelLeft, BarrelDown;
};

#endif // __ENEMY_DONKEYKONG_H__