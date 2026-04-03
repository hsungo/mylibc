#include "../include/sys/syscall.h"

long __syscall0(long number){
    long ret;
    __asm__ __volatile__(
        "movq %1, %%rax\n"   // assembly language
        "syscall\n"
        "movq %%rax, %0"
        : "=r"(ret)         // output register
        : "r"(number)       // input register
        : "%rax"            // clobbered register
    );
    return ret;
}

long __syscall1(long number, long arg1){
    long ret;
    __asm__ __volatile__(
        "movq %1, %%rax\n"                              
        "movq %2, %%rdi\n"
        "syscall\n"
        "movq %%rax, %0"
        : "=r"(ret)                                     
        : "r"(number), "r"(arg1) 
        : "%rax", "%rdi"
    );
    return ret;
}

long __syscall2(long number, long arg1, long arg2){
    long ret;
    __asm__ __volatile__(
        "movq %1, %%rax\n"                              
        "movq %2, %%rdi\n"
        "movq %3, %%rsi\n"
        "syscall\n"
        "movq %%rax, %0"
        : "=r"(ret)                                     
        : "r"(number), "r"(arg1), "r"(arg2)
        : "%rax", "%rdi", "%rsi"
    );
    return ret;
}

long __syscall3(long number, long arg1, long arg2, long arg3){
    long ret;
    __asm__ __volatile__(
        "movq %1, %%rax\n"                              
        "movq %2, %%rdi\n"
        "movq %3, %%rsi\n"
        "movq %4, %%rdx\n"
        "syscall\n"
        "movq %%rax, %0"
        : "=r"(ret)                                     
        : "r"(number), "r"(arg1), "r"(arg2), "r"(arg3)  
        : "%rax", "%rdi", "%rsi", "%rdx"                
    );
    return ret;
}

long __syscall4(long number, long arg1, long arg2, long arg3, long arg4){
    long ret;
    __asm__ __volatile__(
        "movq %1, %%rax\n"                              
        "movq %2, %%rdi\n"
        "movq %3, %%rsi\n"
        "movq %4, %%rdx\n"
        "movq %5, %%r10\n"  // 第4個參數放入 r10
        "syscall\n"
        "movq %%rax, %0"
        : "=r"(ret)                                     
        : "r"(number), "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4)
        : "%rax", "%rdi", "%rsi", "%rdx", "%r10"                
    );
    return ret;
}
