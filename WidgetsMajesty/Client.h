#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <SDL.h>

#include "Image.h"
#include "Widget.h"
#include "Button.h"
#include "WidgetContainer.h"
#include "EventHandler.h"

// it will be threadsafe initially
class Client {
private:	
	SDL_Window* win;
	SDL_Renderer *renderer;

	Client() = default;
	~Client() = default;

	Client(const Client&) = delete;
	Client& operator= (const Client&) = delete;

	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;

	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;

	void initSys();
	void initObjects(ptrSharedWidgetContainer &  wc1, ptrSharedWidgetContainer &  wc2);	
	void execMainLoop(ptrSharedWidgetContainer &  wc1, ptrSharedWidgetContainer &  wc2);
	void completeSys();

public:
	static Client& getInstance();
	void run();
};

#endif // !CLIENT_H
