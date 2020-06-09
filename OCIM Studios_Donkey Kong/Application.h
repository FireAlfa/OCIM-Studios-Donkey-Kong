#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

//Total ammount of Modules
#define NUM_MODULES 10


class Module;


class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;

class ModulePlayer;
class SceneLevel4;
class ModuleParticles;
class ModuleEnemies;

class ModuleCollisions;

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
	update_status Update();


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
	SceneLevel4* lvl4 = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleEnemies* enemies = nullptr;

	ModuleCollisions* collisions = nullptr;

	ModuleRender* render = nullptr;

};

// Global var made extern for Application
extern Application* App;

#endif // __APPLICATION_H__