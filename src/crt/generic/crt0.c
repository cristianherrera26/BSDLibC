/* Note: this is a basic crt0 implementation for non-supported architecture */
/* Public Domain */

#include <unistd.h>

extern int main();

void
_start()
{
	int exit_code = main();
	_exit(exit_code);
}
