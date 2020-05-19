#include "Module.h"

//Initialize the Module
bool Module::Init()
{
	return true;
}


//Does the Pre Update routines of the Module
update_status Module::PreUpdate()
{
	return update_status::UPDATE_CONTINUE;
}

//Does the Update routines of the Module
update_status Module::Update()
{
	return update_status::UPDATE_CONTINUE;
}

//Does the Post Update routines of the Module
update_status Module::PostUpdate()
{
	return update_status::UPDATE_CONTINUE;
}


//Deletes memory of the Module
bool Module::CleanUp()
{
	return true;
}