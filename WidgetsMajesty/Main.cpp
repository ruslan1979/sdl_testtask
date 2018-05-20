#include "Client.h"

int main(int argc, char* argcv[]) {
	auto& client = Client::getInstance();
	client.run();

	return 0;
}
