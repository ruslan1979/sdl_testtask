#pragma once
#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL.h>

class EventHandler
{
public:
	void handleEvent(const SDL_Event& e);
};

#endif