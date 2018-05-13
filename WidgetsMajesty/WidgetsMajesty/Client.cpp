#include <Client.h>

Client & Client::instance()
{
	// TODO: вставьте здесь оператор return
	static Client::Client c;
	return c;
}
