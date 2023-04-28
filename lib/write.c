#define __LIBRARY__
#include "../include/unistd.h"
#include "../include/sys/types.h"

_syscall3(int,write,int,fd,const char *,buf,off_t,count);
