#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	const char *s = "Hi\n";
	size_t len = strlen (s);
	size_t written = 0;
	ssize_t wresult;

	wresult = write(STDOUT_FILENO, s, len);

	return 0;
}
