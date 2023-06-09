#include "include/stdarg.h"
#include "include/unistd.h"

static char printbuf[1024];

static int my_printf(const char *fmt, ...)
{
	va_list args;
	int i;

	va_start(args, fmt);
	write(1,printbuf,i=vsprintf(printbuf, fmt, args));
	va_end(args);
	return i;
}

void _start(void) {
	asm(
			"movq %rsp, %rbp\n"
			"andq $-16, %rsp\n"
			"call main\n"
			"movq %rax, %rdi\n"
			"movq $60, %rax\n"
			"syscall"
	   );
}

void main(void)
{
	char * str = "Hello There\n";
	my_printf("Hello There\n");
	my_printf("Magic %s", str);
}
