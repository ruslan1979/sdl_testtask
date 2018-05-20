#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <SDL.h>

#include "Image.h"
#include "Widget.h"
#include "Button.h"
#include "WidgetContainer.h"
#include "EventHandler.h"

// it will be threadsafe initially
class Client {
private:
	Client() = default;
	~Client() = default;

	Client(const Client&) = delete;
	Client& operator= (const Client&) = delete;

	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;

	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;

public:
	static Client& getInstance();
	void run();
};

#endif // !CLIENT_H
