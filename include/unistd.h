#ifndef UNISTD_H
#define UNISTD_H

#include "stddef.h"

pid_t fork(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t waitpid(pid_t pid, int *wstatus, int options);
int brk(void *addr);
void *sbrk(long increment);

#endif