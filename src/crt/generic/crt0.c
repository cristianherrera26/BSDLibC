/* Note: this is a basic crt0 implementation for non-supported architecture */
#include <unistd.h>

extern int main();

void
_start()
{
	int exit_code = main();
	_exit(exit_code);
}
