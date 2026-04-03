#ifndef MYSYSCALL_H
#define MYSYSCALL_H

#define sys_read 0
#define sys_write 1
#define sys_open 2
#define sys_close 3
#define sys_brk 12
#define sys_fork 57
#define sys_execve 59
#define sys_exit 60
#define sys_wait4 61

long __syscall0(long num);
long __syscall1(long num, long a1);
long __syscall2(long num, long a1, long a2);
long __syscall3(long num, long a1, long a2, long a3);
long __syscall4(long num, long a1, long a2, long a3, long a4);

#endif

