#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

//Total ammount of Modules
#define NUM_MODULES 19


class Module;


class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;

class ModulePlayer;
class SceneIntro;
class SceneLevel1Intro;
class SceneLevel1;
class SceneLevel2;
class SceneLevel4;
class SceneVictory;
class ModuleParticles;
class ModuleEnemies;
class ModuleObject;

class ModuleCollisions;
class ModuleFadeToBlack;
class ModuleFonts;
class ModuleDebugInfo;

class ModuleRender;


//App Class
class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();



	//Initializes all modules
	bool Init();


	//Updates all modules (PreUpdate, Update and PostUpdate)
	Update_Status Update();


	//Releases all the application data
	bool CleanUp();


public:

	//Modules Array, to execute the modules in order
	Module* modules[NUM_MODULES];


	//Declaration of each module

	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;

	ModulePlayer* player = nullptr;

	SceneIntro* sceneIntro = nullptr;
	SceneLevel1Intro* sceneLevel1Intro = nullptr;
	SceneLevel1* sceneLevel1 = nullptr;
	SceneLevel2* sceneLevel2 = nullptr;
	SceneLevel4* sceneLevel4 = nullptr;
	SceneVictory* sceneVictory = nullptr;

	ModuleEnemies* enemies = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleObject* objects = nullptr;


	ModuleCollisions* collisions = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleFonts* fonts = nullptr;
	ModuleDebugInfo* debugInfo = nullptr;

	ModuleRender* render = nullptr;

};

// Global var made extern for Application
extern Application* App;

#endif // __APPLICATION_H__