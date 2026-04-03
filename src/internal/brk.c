#include "../../include/sys/syscall.h"
#include "../../include/string.h"

static void* current_brk = 0;

void *sbrk(long increment){
    if(current_brk == 0){ //initialize
        current_brk = (void*)__syscall1(sys_brk, 0);
    }

    void *old_brk = current_brk;
    void *new_brk = (void*)((char*)current_brk + increment);

    if(__syscall1(sys_brk, (long)new_brk) < 0){
        return (void*) -1;
    }
    current_brk = new_brk;
    return old_brk;
}