/*
 * SYSCALL_DEFINE1(epoll_create, int, size)
 *
 * On success, returns a nonnegative file descriptor.
 * On error, -1 is returned, and errno is set to indicate the error.
 */
#include "trinity.h"
#include "sanitise.h"

struct syscall syscall_epoll_create = {
	.name = "epoll_create",
	.num_args = 1,
	.arg1name = "size",
	.arg1type = ARG_LEN,
	.retval = ARG_FD,
};