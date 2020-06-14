#ifndef __MODULEOBJECT_H__
#define __MODULEOBJECT_H__

#include "Module.h"
#include "Object.h"

#define MAX_OBJ 15

struct SDL_Texture;

enum class ObjectType
{
	NO_TYPE,
	BAG
	//TODO ADD types of objects
};

struct ObjectSpawnPoint
{
	int x, y;
	ObjectType Type = ObjectType::NO_TYPE;
	
};



class ModuleObject : public Module
{
public:
	//Constructor
	ModuleObject(bool startEnabled);

	//Destructor
	~ModuleObject();

	//Called when the module is activated
	//By now we will consider all modules to be permanently active
	virtual bool Start();

	// Called at the beginning of the application loop
	// Removes all particles pending to delete
	Update_Status PreUpdate() override;

	// Called at the middle of the application loop
	// Iterates all the particles and calls its Update()
	// Removes any "dead" particles
	Update_Status Update() override;

	// Called at the end of the application loop
	// Iterates all the particles and draws them
	Update_Status PostUpdate() override;

	//Called at the end of the application
	virtual bool CleanUp();

	// Called when an enemi collider hits another collider
	// The enemy is destroyed and an explosion particle is fired
	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddObject(ObjectType type, int x, int y);

	// Iterates the queue and checks for camera position
	void HandleObjectSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleObjectDespawn();




private:
	// Spawns a new enemy using the data from the queue
	void SpawnObject(const ObjectSpawnPoint& info);

	// A queue with all spawn points information
	ObjectSpawnPoint spawnQueue[MAX_OBJ];

	// All spawned enemies in the scene
	Object* objects[MAX_OBJ] = { nullptr };

	// The enemies sprite sheet
	SDL_Texture* objTexture = nullptr;

	//pickup FX
	int objectPickedFx = 0;
};
#endif // !__MODULEOBJECT_H__

