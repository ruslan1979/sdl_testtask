#pragma once
#ifndef CLIENT_H
#define CLIENT_H

// it will be threadsafe initially
// taken from https://ru.stackoverflow.com/questions/327136/singleton-%D0%B8-%D1%80%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F

class Client {
private:
	Client();
	~Client();

	Client(Client const&) = delete;
	Client& operator= (Client const&) = delete;

public:
	static Client& instance();
};

#endif // !CLIENT_H

