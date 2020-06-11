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

#include "ModuleRender.h"


#include "SDL/include/SDL_scancode.h"
#include <stdio.h>



ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	name = "player";
	
	//
	//
	//
	//Animation pushbacks
	//
	//
	//
}

ModulePlayer::~ModulePlayer()
{

}

//Load the player textures
bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;
	
	destroyed = false;
	canClimb = false;

	//
	//
	//
	//Set initial position
	//
	//
	//

	//
	//
	//
	//Load Player textures files & set currentAnimation
	//
	//
	//

	//
	//
	//
	//Load Player FX files
	//
	//
	//
	jumpFx = App->audio->LoadFx("Assets/Fx/jump.ogg");

	//
	//
	//
	//Create Player collider
	//
	//
	//

	//Font
	char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	scoreFont = App->fonts->Load("Assets/Fonts/rtype_font3.png", lookupTable, 2); //change file

	return ret;
}

//Main player Update
Update_Status ModulePlayer::Update()
{
	//GamePad& pad = App->input->pads[0];

	UpdateState();
	UpdateLogic();

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
			App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_DOWN)
			ChangeState(state, RUNNING);

		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
			ChangeState(state, JUMPING);

		// TODO 5: Fill in the transition condition to start climbing

		// TODO 0: Notice how we are changing into HAMMER_IDLE state when pressing H
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

		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN)
			ChangeState(state, HAMMER_RUNNING);

		/*if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN && canClimb)
			ChangeState(state, CLIMBING);
		*/
		break;
	}

	case JUMPING:
	{
		if (jumpCountdown <= 0)
		{
			jumpCountdown = 30;
			if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT ||
				App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
				ChangeState(state, RUNNING);
			else
				ChangeState(state, IDLE);
		}
		break;
	}

	case HAMMER_IDLE:
	{
		// TODO 2: Check the condition to go back to IDLE state. If fulfilled, change the state.
		if (App->input->keys[SDL_SCANCODE_H] == Key_State::KEY_DOWN)
			ChangeState(state, IDLE);

		// TODO 3: Add all the logic behind HAMMER_RUN state

		// TODO 3.1: Check the condition. If fulfilled, change the state to HAMMER_RUN
/*		if (App->input->keys[SDL_SCANCODE_A] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_D] != Key_State::KEY_REPEAT)
		{
			ChangeState(state, HAMMER_RUNNING);
		}*/


		break;
	}
	case HAMMER_RUNNING:
		// TODO 3: Add all the logic behind HAMMER_RUN state
		// TODO 3.4: Lastly, go back to HAMMER_IDLE when the condition is fulfilled

		break;

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
		position.x += speed * facingDirection;
		currentAnimation->Update();
		break;
	}
	case(JUMPING):
	{
		--jumpCountdown;
		if (jumpCountdown >= 0 && jumpCountdown < 15)
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

	case(HAMMER_RUNNING):
	{
		// TODO 3: Add all the logic behind HAMMER_RUN state
		// TODO 3.3: Update HAMMER_RUN state logic

		break;
	}

	case(CLIMBING):
	{
		// TODO 5: Update climbing logic - Only move when the player is pressing "W"

		position.y += speed * upDownDirection;
		currentAnimation->Update();
		break;
	}
	}

	// Simply updating the collider position to match our current position
	//collider->SetPos(position.x + 2, position.y + 14);
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
		// TODO 1: Change the current animation to match the new state (very similar to IDLE case)
		currentAnimation = &(facingDirection == -1 ? hammerIdleAnim_Left : hammerIdleAnim_Right);
		break;
	}
	case(HAMMER_RUNNING):
	{
		// TODO 3: Add all the logic behind HAMMER_RUN state
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
			facingDirection = -1;
		else
			facingDirection = 1;
		// TODO 3.2: When changing the state, change to the proper animation
		currentAnimation = &(facingDirection == -1 ? hammerRunAnim_Left : hammerRunAnim_Right);
		break;
	}
	case (CLIMBING):
	{
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN ||
			App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
			upDownDirection = 1;
		else
			upDownDirection = -1;
		currentAnimation = &(upDownDirection == 1 ? climb_Up : climb_Down);
		break;
		// TODO 5: Change climbing animation when changing the state

	}
	}

	state = newState;
}

//Post Update
Update_Status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		/*SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(playerTexture, position.x, position.y, &rect);*/
	}



	//Debug Gamepad
	if (debugGamepadInfo == true)
		DebugDrawGamepadInfo();
	else
		App->fonts->BlitText(5, 10, scoreFont, "press f2 to display gamepad debug info");

	return Update_Status::UPDATE_CONTINUE;
}

//Controls what the player does when it collides with another collider
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	//
	//
	//
	//Collision control
	//
	//
	//

	/*if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::LADDER)
	{
		canClimb = true;
	}

	if (c2->type == Collider::Type::TOP_LADDER)
	{
		// TODO 5: The player has reached the top of the ladder, stop climbing


	}*/
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