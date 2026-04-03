#include "../include/sys/syscall.h"

extern int main(int argc, char **argv);

void _start_c(long *sp){
    long argc = sp[0];
    char **argv = (char**)(++sp);

    int ret = main((int)argc, argv);

    __syscall1(sys_exit, ret);
}

__asm__(
    ".global _start\n"
    "_start:\n"
    "mov %rsp, %rdi\n"
    "and $-16, %rsp\n"
    "call _start_c\n"
);