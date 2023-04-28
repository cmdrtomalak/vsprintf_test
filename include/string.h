#ifndef _STRING_H_
#define _STRING_H_

#ifndef NULL
#define NULL ((void *) 0)
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

extern char * strerror(int errno);

extern inline int strlen(const char * s)
{
	int res;
#ifdef __X86_64__
asm volatile (
	"cld\n\t"
	"repne\n\t"
	"scasb\n\t"
	"notl %0\n\t"
	"decl %0"
	:"=c" (res)
	:"D" (s),"a" (0),"0" (0xffffffff)
	:"memory");

	return (size_t)res;
}
#endif

#ifdef __X86_64__
    asm volatile (
        "movq $-1, %%rcx\n\t"  // Set RCX to -1
        "movq $0, %%rdi\n\t"  // Set RDI to 0
        "xorl %%eax, %%eax\n\t"  // Set EAX to 0
        "cld\n\t"
        "repne\n\t"
        "scasb\n\t"
        "notq %%rcx\n\t"
        "decq %%rcx\n\t"
        : "=c" (res)
        : "D" (s)
        : "rax", "memory"
    );
    return res;
#endif

#endif /* _STRING_H_ */
