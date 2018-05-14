#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "SDL.h"
#include "Widget.h"

using namespace std;

// it will be threadsafe initially
// taken from https://ru.stackoverflow.com/questions/327136/singleton-%D0%B8-%D1%80%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F

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

