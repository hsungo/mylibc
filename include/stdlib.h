#ifndef STDLIB_H
#define STDLIB_H

#include "stddef.h"

int system(const char *command);
void *malloc(size_t size);
void free(void *ptr);

#endif