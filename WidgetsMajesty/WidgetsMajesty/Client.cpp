#include <Client.h>

Client & Client::instance()
{
	// TODO: �������� ����� �������� return
	static Client::Client c;
	return c;
}
