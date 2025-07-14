#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int fork(void) {
    errno = EAGAIN; // No more processes
    return -1;
}
