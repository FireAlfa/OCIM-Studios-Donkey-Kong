#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <windows.h>


//Defines the Log

#define LOG(txt) OutputDebugString(txt)


#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0


enum class update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};



// Global Configuration

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 960

#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0
#define REN_VSYNC 1


#endif // __GLOBALS_H__