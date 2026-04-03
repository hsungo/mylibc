#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>
#include "sys/syscall.h"  
#include "stddef.h"
#include "string.h"

#define BUFFER_SIZE 2

int printf(const char *format, ...);
int scanf(const char *format, ...);

#endif