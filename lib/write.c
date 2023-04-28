#define __LIBRARY__
#include "../include/unistd.h"
#include "../include/sys/types.h"

_syscall3(int,write,int,fd,const char *,buf,off_t,count);

ssize_t my_write(int fd, const void *buf, size_t count) {
	ssize_t ret;

	asm volatile (
        "syscall"
        : "=a" (ret)
        //                 EDI      RSI       RDX
        : "0"(__NR_write), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11", "memory"
	);

	return ret;
}
