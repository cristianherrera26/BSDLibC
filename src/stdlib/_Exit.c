#include <unistd.h>

void
_Exit(int exit_code)
{
	_exit(exit_code);
}
