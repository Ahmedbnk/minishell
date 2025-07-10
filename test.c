#include <stdio.h>

void handler(int sig)
{
	exit (69);
}

int main()
{
	signal(2, handler);
	pause();
}
