#ifndef _STDARG_H
#define _STDARG_H

#define va_start(v,l)          __builtin_va_start(v,l)
#define va_end(v)              __builtin_va_end(v)
#define va_arg(v,l)            __builtin_va_arg(v,l)

#ifndef __VA_LIST
#define __VA_LIST
typedef __builtin_va_list va_list;
#endif /* __VA_LIST */

#endif /* _STDARG_H */
