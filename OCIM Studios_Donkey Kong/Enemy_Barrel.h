#ifndef __ENEMY_BARREL_H__
#define __ENEMY_BARREL_H__

#include "Enemy.h"
#include "Animation.h"


class Enemy_Barrel : public Enemy
{
public:
	//Constructor
	Enemy_Barrel(int x, int y, int direction);

	// Checks for inputs (or timers) and changes the player state accordingly
	void UpdateState();

	// Updates the logic of the player depending on the current state
	void UpdateLogic();

	// Transition from one state to a new one. Changes animations, resets variables,...
	void ChangeState(Enemy_State previousState, Enemy_State newState);

	//State of the enemy
	Enemy_State state = ENEMY_MOVING;

	//
	//Enemy Flags
	//
	bool rampRight = false;
	bool rampLeft = false;



private:

	Animation BarrelAnim, BarrelFall;
};
	
#endif // !__ENEMY_BARREL_H__