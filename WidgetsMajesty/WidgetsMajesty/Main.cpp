#include "Client.h"

int main(int argc, char* argcs[]) {
	auto& client = Client::getInstance();
	client.run();
	
	return 0;
}
