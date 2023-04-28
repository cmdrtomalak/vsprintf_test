#ifndef _UNISTD_H
#define _UNISTD_H

#include "sys/types.h"

extern int errno;

#ifdef __LIBRARY__

#define __NR_write	4

#define _syscall3(type,name,atype,a,btype,b,ctype,c) \
type name(atype a,btype b,ctype c) \
{ \
long __res; \
__asm__ volatile ("int $0x80" \
	: "=a" (__res) \
	: "0" (__NR_##name),"b" ((long)(a)),"c" ((long)(b)),"d" ((long)(c))); \
if (__res>=0) \
	return (type) __res; \
errno=-__res; \
return -1; \
}

#endif /* __LIBRARY__ */


int write(int fildes, const char * buf, off_t count);

#endif
