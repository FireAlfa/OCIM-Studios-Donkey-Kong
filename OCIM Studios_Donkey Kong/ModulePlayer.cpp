#include "ModulePlayer.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include "SceneLevel4.h"
#include "SceneLevel1.h"

#include "ModuleRender.h"


#include "SDL/include/SDL_scancode.h"
#include <stdio.h>



ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	name = "player";



	//
	//Animation pushbacks
	//
	//IdleAnims
	idleAnim_Left.PushBack({ 51, 17, 12, 16 });
	idleAnim_Right.PushBack({ 68, 17, 12, 16 });



	//Running Anims
	//   Left
	runningAnim_Left.PushBack({ 0, 0, 15, 16 });
	runningAnim_Left.PushBack({ 24, 0, 15, 16 });
	//	Right
	runningAnim_Right.PushBack({ 68, 0, 15, 16});
	runningAnim_Right.PushBack({ 44, 0, 15, 16});

	runningAnim_Left.speed = runningAnim_Right.speed = 0.1f;



	//	Jumping Left
	jumpAnim_Left.PushBack({ 34, 17, 15, 16 });
	jumpAnim_Left.PushBack({ 17, 17, 16, 15 });
	//	Jumping Right
	jumpAnim_Right.PushBack({ 85, 17, 15, 16 });
	jumpAnim_Right.PushBack({ 102, 17, 16, 15 });

	jumpAnim_Left.speed = jumpAnim_Right.speed = 0.1f;
	jumpAnim_Left.loop = jumpAnim_Right.loop = false;



	//Climb
	climb.PushBack({51, 34, 13, 16});
	climb_Up.PushBack({ 68, 34, 13, 16 });
	climb_Up.speed = 0.1f;

	//ClimbUp
	climb_Up.PushBack({ 85, 34, 14, 15 }); 
	climb_Up.PushBack({ 102, 34, 16, 12 });
	climb_Up.PushBack({ 119, 34, 16, 15 });
	climb_Up.speed = 0.1f;

	//ClimbDown
	climb_Down.PushBack({ 0, 34, 16, 15 });
	climb_Down.PushBack({ 17, 34, 16, 12 });
	climb_Down.PushBack({ 34, 34, 14, 15 });
	climb_Down.speed = 0.1f;



	//	Hammer Idle
	//		Left
	hammerIdleAnim_Left.PushBack({ 142, 0, 25, 26 });
	hammerIdleAnim_Left.PushBack({ 116, 68, 25, 26 });

	//		Right
	hammerIdleAnim_Right.PushBack({ 142, 34, 25, 26 });
	hammerIdleAnim_Right.PushBack({ 142, 68, 25, 26 });

	hammerIdleAnim_Left.speed = hammerIdleAnim_Right.speed = 0.1f;


	//	HammerRunning
	//		Left
	hammerRunAnim_Left.PushBack({ 0, 68, 29, 26 });
	hammerRunAnim_Left.PushBack({ 29, 68, 29, 26 });
	hammerRunAnim_Left.PushBack({ 58, 68, 29, 26 });     
	hammerRunAnim_Left.PushBack({ 87, 68, 29, 26 });

	//		Right
	hammerRunAnim_Right.PushBack({ 87, 94, 29, 26 });
	hammerRunAnim_Right.PushBack({ 58, 94, 29, 26 });
	hammerRunAnim_Right.PushBack({ 29, 94, 29, 26 });
	hammerRunAnim_Right.PushBack({ 0, 94, 29, 26 });
	hammerRunAnim_Left.speed = hammerRunAnim_Right.speed = 0.1f;

}

ModulePlayer::~ModulePlayer()
{

}

//Load the player textures
bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;


	//
	//Set initial position
	//
	position.x = 1;
	position.y = 232;


	//
	//Load Player textures files & set currentAnimation
	//
	playerTexture = App->textures->Load("Assets/Sprites/Mario_Sprites.png");
	currentAnimation = &idleAnim_Right;


	//
	//Load Player FX files
	//
	jumpFx = App->audio->LoadFx("Assets/Fx/jump.ogg");


	//
	//Create Player collider
	//
	playerCollider = App->collisions->AddCollider({ position.x, position.y, 12, 16 }, Collider::Type::PLAYER, this);
	playerCenterCollider = App->collisions->AddCollider({ position.x + 5, position.y, 3, 16 }, Collider::Type::PLAYER_CENTER, this);
	playerFeetCollider = App->collisions->AddCollider({ position.x + 5, position.y + 14, 3, 2 }, Collider::Type::PLAYER_FEET, this);


	//
	//Player flags
	//
	destroyed = false;
	canClimb = false;
	canGoDownStairs = false;


	//Font
	char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	scoreFont = App->fonts->Load("Assets/Fonts/rtype_font3.png", lookupTable, 2); //change file

	return ret;
}

//Main player Update
Update_Status ModulePlayer::Update()
{
	GamePad& pad = App->input->pads[0];


	//
	//State updates
	//
	UpdateState();
	UpdateLogic();

	canClimb = false;
	canGoDownStairs = false;
	rampRight = false;
	rampLeft = false;

	if (App->input->keys[SDL_SCANCODE_G] == KEY_DOWN)
		debugGamepadInfo = !debugGamepadInfo;


	return Update_Status::UPDATE_CONTINUE;
}

//Control input and states
void ModulePlayer::UpdateState()
{
	switch (state)
	{
	case IDLE:
	{
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
			ChangeState(state, RUNNING);

		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
			ChangeState(state, JUMPING);

		if (canClimb == true &&
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN))
			ChangeState(state, CLIMBING_IDLE);

		if (canGoDownStairs == true &&
			(App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN))
			ChangeState(state, CLIMBING_DOWN);

		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN)
			ChangeState(state, HAMMER_IDLE);

		break;
	}

	case RUNNING:
	{
		if (App->input->keys[SDL_SCANCODE_A] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_D] != Key_State::KEY_REPEAT)
		{
			ChangeState(state, IDLE);
		}

		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
			ChangeState(state, JUMPING);

		if (canClimb == true &&
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN)
			ChangeState(state, CLIMBING_IDLE);

		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN)
			ChangeState(state, HAMMER_RUNNING);

		break;
	}

	case JUMPING:
	{
		if (/*jumpCountdown <= 0*/ lastCollider == Collider::Type::WALL)
		{
			jumpCountdown = 30;
			if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT ||
				App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
			{
				lastCollider = -2;
				ChangeState(state, RUNNING);
			}
			else
			{
				lastCollider = -2;
				ChangeState(state, IDLE);
			}
		}

		break;
	}

	case CLIMBING_DOWN:
	{
		if (canGoDownStairs == false)
			ChangeState(state, CLIMBING_IDLE);

		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN)
			ChangeState(state, CLIMBING_UP);

		break;
	}

	case CLIMBING_UP:
	{
		if (canGoDownStairs == false)
		{
			position.y += speed;
			ChangeState(state, IDLE);
		}
			

		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN)
			ChangeState(state, CLIMBING_DOWN);

		break;
	}


	case CLIMBING_IDLE:
	{
		if (canClimb == true &&
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
			ChangeState(state, CLIMBING_RUNNING);

		if (canGoDownStairs == true && upDownDirection == 1 &&
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT))
			ChangeState(state, CLIMBING_DOWN);

		if (canGoDownStairs == true && upDownDirection == -1 &&
			(App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT))
			ChangeState(state, CLIMBING_UP);


		if (canClimb == false)
			ChangeState(state, IDLE);
			

		break;
	}

	case CLIMBING_RUNNING:
	{
		if (canGoDownStairs == true)
		{
			if (upDownDirection == -1) {
				ChangeState(state, CLIMBING_UP);
			}
			else
			{
				ChangeState(state, CLIMBING_DOWN);
			}
			break;
		}

		if (App->input->keys[SDL_SCANCODE_W] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_S] != Key_State::KEY_REPEAT)
			ChangeState(state, CLIMBING_IDLE);

		if (canClimb == false)
			ChangeState(state, IDLE);

		break;
	}

	case HAMMER_IDLE:
	{
		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN)
			ChangeState(state, IDLE);


		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN)
		{
			ChangeState(state, HAMMER_RUNNING);
		}


		break;
	}
	case HAMMER_RUNNING:
	{
		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN)
			ChangeState(state, RUNNING);


		if (App->input->keys[SDL_SCANCODE_A] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_D] != Key_State::KEY_REPEAT)
		{
			ChangeState(state, HAMMER_IDLE);
		}

		break;
	}

	default:
		break;
	}
	
}

//Control what each state does
void ModulePlayer::UpdateLogic()
{
	switch (state)
	{
	case(IDLE):
	{
		// Nothing to do here :)
		break;
	}
	case(RUNNING):
	{
		if (rampRight == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x == aux.x ) //Go Up Looking Right//
				{
					position.y -= speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y <= aux.y - 15 && playerCenterCollider->rect.x + 2 == aux.x) //Go Down Looking Left//
				{
					position.y += speed;
				}
			}
		}

		if (rampLeft == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y < aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Down Looking Right
				{
					position.y += speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x + 2 == aux.x) //Go Up Looking Left//
				{
					position.y -= speed;
				}
			}
		}

		position.x += speed * facingDirection;
		currentAnimation->Update();

		break;
	}
	case(JUMPING):
	{
		--jumpCountdown;
		if (/*jumpCountdown > 0 &&*/ jumpCountdown < 15)
		{
			++position.y;
		}
		else if (jumpCountdown < 30)
		{
			--position.y;
		}
		position.x += speed * jumpDirection;
		currentAnimation->Update();

		break;
	}

	case(HAMMER_IDLE):
	{
		currentAnimation->Update();

		break;
	}

	case(HAMMER_RUNNING):///////////////
	{
		if (rampRight == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Up Looking Right//
				{
					position.y -= speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y <= aux.y - 15 && playerCenterCollider->rect.x + 2 == aux.x) //Go Down Looking Left//
				{
					position.y += speed;
				}
			}
		}

		if (rampLeft == true)
		{
			//Right
			if (facingDirection == 1)
			{
				if (playerCenterCollider->rect.y < aux.y - 14 && playerCenterCollider->rect.x == aux.x) //Go Down Looking Right
				{
					position.y += speed;
				}
			}

			//Left
			if (facingDirection == -1)
			{
				if (playerCenterCollider->rect.y >= aux.y - 14 && playerCenterCollider->rect.x + 2 == aux.x) //Go Up Looking Left//
				{
					position.y -= speed;
				}
			}
		}

		position.x += speed * facingDirection;
		currentAnimation->Update();

		break;
	}

	case(CLIMBING_DOWN):
	{
		if (canGoDownStairs == true)
		{
			position.y += speed * upDownDirection;
			currentAnimation->Update();
		}

		break;
	}

	case(CLIMBING_UP):
	{
		if (canGoDownStairs == true)
		{
			position.y += speed * upDownDirection;
			currentAnimation->Update();
		}

		break;
	}

	case(CLIMBING_IDLE):
	{
		currentAnimation->Update();

		break;
	}

	case(CLIMBING_RUNNING):
	{
		if (canClimb == true)
		{
			position.y += speed * upDownDirection;
			currentAnimation->Update();
		}
	}

	}


	switch (lastCollider)
	{
	case Collider::Type::NONE:
		break;
	case Collider::Type::WALL:
		position.y -= speed;
		lastCollider = Collider::Type::NONE;
		break;
	case Collider::Type::GOUPWALL:
	case Collider::Type::RAMP_RIGHT:
	case Collider::Type::RAMP_LEFT:
	case Collider::Type::PLAYER:
	case Collider::Type::PLAYER_CENTER:
	case Collider::Type::ENEMY:
	case Collider::Type::STAIR:
	case Collider::Type::TOP_STAIR:
	case Collider::Type::BUTTON:
	case Collider::Type::TOPWALL:
	case Collider::Type::LEFTWALL:
	case Collider::Type::RIGHTWALL:
	case Collider::Type::GRAVITYWALLS:
	case Collider::Type::PEACH:
	case Collider::Type::DK:
		break;
	default:
			position.y += speed;
		break;
	}

	

	// Simply updating the collider position to match our current position
	playerCollider->SetPos(position.x, position.y);
	playerCenterCollider->SetPos(position.x + 5, position.y);
	playerFeetCollider->SetPos(position.x + 5, position.y + 14);
}

//Change the State
void ModulePlayer::ChangeState(Player_State previousState, Player_State newState)
{
	switch (newState)
	{
	case(IDLE):
	{
		currentAnimation = &(facingDirection == -1 ? idleAnim_Left : idleAnim_Right);
		break;
	}
	case(RUNNING):
	{
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
			facingDirection = -1;
		else
			facingDirection = 1;
		currentAnimation = &(facingDirection == -1 ? runningAnim_Left : runningAnim_Right);
		break;
	}
	case(JUMPING):
	{
		App->audio->PlayFx(jumpFx);

		if (previousState == IDLE)
			jumpDirection = 0;
		else
			jumpDirection = facingDirection;

		currentAnimation = &(facingDirection == -1 ? jumpAnim_Left : jumpAnim_Right);
		break;
	}
	case(HAMMER_IDLE):
	{
		currentAnimation = &(facingDirection == -1 ? hammerIdleAnim_Left : hammerIdleAnim_Right);
		break;
	}
	case(HAMMER_RUNNING):
	{
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
			facingDirection = -1;
		else
			facingDirection = 1;

		currentAnimation = &(facingDirection == -1 ? hammerRunAnim_Left : hammerRunAnim_Right);
		break;
	}

	case(CLIMBING_DOWN):
	{
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
			upDownDirection = 1;
		else
			upDownDirection = -1;

		currentAnimation = &climb_Down;
		break;
	}

	case(CLIMBING_UP):
	{
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
			upDownDirection = -1;
		else
			upDownDirection = 1;

		currentAnimation = &climb_Up;
		break;
	}

	case(CLIMBING_IDLE):
	{
		break;
	}
	case (CLIMBING_RUNNING):
	{
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
			upDownDirection = -1;
		else if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
			upDownDirection = 1;

		currentAnimation = &(upDownDirection == -1 ? climb_Up : climb_Down);
		break;

	}
	}

	lastCollider = Collider::Type::NONE;

	state = newState;
}

//Post Update
Update_Status ModulePlayer::PostUpdate()
{
	//
	//Draw Player
	//
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		if (state == HAMMER_IDLE || state == HAMMER_RUNNING)
		{
			if (facingDirection == -1)
			{
				App->render->Blit(playerTexture, position.x - 13, position.y - 10, &rect);
			}
			else {
				App->render->Blit(playerTexture, position.x, position.y - 10, &rect);
			}
		}
		else
		{
			App->render->Blit(playerTexture, position.x, position.y, &rect);
		}
	}



	//Debug Gamepad
	if (debugGamepadInfo == true)
		DebugDrawGamepadInfo();
	else
		App->fonts->BlitText(5, 10, scoreFont, "press g to display gamepad debug info");

	return Update_Status::UPDATE_CONTINUE;
}

//Controls what the player does when it collides with another collider
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	//
	//Collision control
	//

	if (c1 == playerCenterCollider && c2->type == Collider::Type::STAIR)
	{
		canClimb = true;
		lastCollider = Collider::Type::STAIR;
	}

	if (c1 == playerCenterCollider && c2->type == Collider::Type::TOP_STAIR) {
		canClimb = true;
		canGoDownStairs = true;
		canGoUpStairs = true;
		lastCollider = Collider::Type::TOP_STAIR;
	}

    if (c1 == playerCollider && c2->type == Collider::Type::TOPWALL)
	{
		position.y += speed;
		lastCollider = Collider::Type::TOPWALL;
	}

	if (c1 == playerCollider && c2->type == Collider::Type::LEFTWALL)
	{
		position.x += speed;
		lastCollider = Collider::Type::LEFTWALL;
	}

	if (c1 == playerCollider && c2->type == Collider::Type::RIGHTWALL)
	{
		position.x -= speed;
		lastCollider = Collider::Type::RIGHTWALL;
	}
	if (c1 == playerFeetCollider && c2->type == Collider::Type::WALL)
	{
 		//position.y -= speed;
		canClimb = false;
		lastCollider = Collider::Type::WALL;
	}
	
	if (c1 == playerCenterCollider && c2->type == Collider::Type::GRAVITYWALLS)
	{
		//changeHeightUp= true;
		position.y += speed;
	}
	

	/*if (c1 == playerCenterCollider && c2->type == Collider::Type::GOUPWALL && facingDirection == -1)
	{
		position.y -= speed;
	}*/
	if (c1 == playerFeetCollider && c2->type == Collider::Type::RAMP_RIGHT)
	{
		rampRight = true;
		aux = c2->GetRect();
		lastCollider = Collider::Type::RAMP_RIGHT;
	}

	if (c1 == playerFeetCollider && c2->type == Collider::Type::RAMP_LEFT)
	{
		rampLeft = true;
		aux = c2->GetRect();
		lastCollider = Collider::Type::RAMP_LEFT;
	}
}

//Draw GamePad Debug
void ModulePlayer::DebugDrawGamepadInfo()
{
	GamePad& pad = App->input->pads[0];

	sprintf_s(scoreText, 150, "pad 0 %s, press 1/2/3 for rumble", (pad.enabled) ? "plugged" : "not detected");
	App->fonts->BlitText(5, 10, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "buttons %s %s %s %s %s %s %s %s %s %s %s",
		(pad.a) ? "a" : "",
		(pad.b) ? "b" : "",
		(pad.x) ? "x" : "",
		(pad.y) ? "y" : "",
		(pad.start) ? "start" : "",
		(pad.back) ? "back" : "",
		(pad.guide) ? "guide" : "",
		(pad.l1) ? "lb" : "",
		(pad.r1) ? "rb" : "",
		(pad.l3) ? "l3" : "",
		(pad.r3) ? "r3" : ""
	);
	App->fonts->BlitText(5, 20, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "dpad %s %s %s %s",
		(pad.up) ? "up" : "",
		(pad.down) ? "down" : "",
		(pad.left) ? "left" : "",
		(pad.right) ? "right" : ""
	);
	App->fonts->BlitText(5, 30, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "left trigger  %0.2f", pad.l2);
	App->fonts->BlitText(5, 40, scoreFont, scoreText);
	sprintf_s(scoreText, 150, "right trigger %0.2f", pad.r2);
	App->fonts->BlitText(5, 50, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "left thumb    %.2fx, %0.2fy", pad.l_x, pad.l_y);
	App->fonts->BlitText(5, 60, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "   deadzone   %0.2f", pad.l_dz);
	App->fonts->BlitText(5, 70, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "right thumb   %.2fx, %0.2fy", pad.r_x, pad.r_y);
	App->fonts->BlitText(5, 80, scoreFont, scoreText);

	sprintf_s(scoreText, 150, "   deadzone   %0.2f", pad.r_dz);
	App->fonts->BlitText(5, 90, scoreFont, scoreText);
}