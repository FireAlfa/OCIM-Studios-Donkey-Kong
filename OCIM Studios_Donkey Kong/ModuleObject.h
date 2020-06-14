#ifndef __MODULEOBJECT_H__
#define __MODULEOBJECT_H__

#include "Module.h"
#include "Object.h"


enum class ObjectType
{
	NO_TYPE,
	BAG
	//TODO ADD types of objects
};

struct obj_SpawnPoint
{
	//ObjectType;
};



class ModuleObject : public Module
{
public:
	ModuleObject(bool startEnabled);

	~ModuleObject();



	//Called at the beginning of the application execution
	virtual bool Init();

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






private:
};
#endif // !__MODULEOBJECT_H__

