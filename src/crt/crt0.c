#include <unistd.h>

extern int main();

void
_start()
{
	int ret = main();
	_exit(ret);
}
