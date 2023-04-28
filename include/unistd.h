#ifndef _UNISTD_H
#define _UNISTD_H

#include "sys/types.h"

extern int errno;

#ifdef __LIBRARY__

#define __NR_write	1

#ifdef __X86_64__
#define _syscall3(type,name,atype,a,btype,b,ctype,c) \
type name(atype a,btype b,ctype c) \
{ \
long __res; \
asm volatile ("syscall" \
	: "=a" (__res) \
	: "0" (__NR_##name),"D" ((long)(a)),"S" ((long)(b)),"d" ((long)(c)) \
	: "rcx", "r11", "memory"); \
if (__res>=0) \
	return (type) __res; \
errno=-__res; \
return -1; \
}
#endif

#ifdef __APPLE_CC__
#define _syscall3(type,name,atype,a,btype,b,ctype,c) \
type name(atype a,btype b,ctype c) \
{ \
long __res; \
asm volatile ("mov x16, %0\n" \
"mov x0, %1\n" \
"mov x1, %2\n" \
"mov x2, %3\n" \
"svc 0x80\n" \
: "=r" (__res) \
: "r" (__NR_##name),"r" ((long)(a)),"r" ((long)(b)),"r" ((long)(c)) \
: "x0", "x1", "x2", "x16", "memory"); \
if (__res>=0) \
	return (type) __res; \
errno=-__res; \
return -1; \
}
#endif

#endif /* __LIBRARY__ */


int write(int fildes, const char * buf, off_t count);

#endif
