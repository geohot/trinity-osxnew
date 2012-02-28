/*
 * SYSCALL_DEFINE6(futex, u32 __user *, uaddr, int, op, u32, val,
	 struct timespec __user *, utime, u32 __user *, uaddr2, u32, val3)
 */
#include <linux/futex.h>

#include "trinity.h"
#include "sanitise.h"

struct syscall syscall_futex = {
	.name = "futex",
	.num_args = 6,
	.arg1name = "uaddr",
	.arg1type = ARG_ADDRESS,
	.arg2name = "op",
	.arg2type = ARG_LIST,
	.arg2list = {
		.num = 13,
		.values = { FUTEX_WAIT, FUTEX_WAKE, FUTEX_FD, FUTEX_REQUEUE,
			FUTEX_CMP_REQUEUE, FUTEX_WAKE_OP, FUTEX_LOCK_PI, FUTEX_UNLOCK_PI,
			FUTEX_TRYLOCK_PI, FUTEX_WAIT_BITSET, FUTEX_WAKE_BITSET, FUTEX_WAIT_REQUEUE_PI,
			FUTEX_CMP_REQUEUE_PI,
		},
	},
	.arg3name = "val",
	.arg4name = "utime",
	.arg4type = ARG_ADDRESS,
	.arg5name = "uaddr2",
	.arg5type = ARG_ADDRESS,
	.arg6name = "val3",
};