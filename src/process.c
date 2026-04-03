#include "../include/stdlib.h"
#include "../include/unistd.h"
#include "../include/sys/syscall.h"
#include "../include/stddef.h"

pid_t fork(void) {
    return (pid_t)__syscall0(sys_fork);
}

int execve(const char *pathname, char *const argv[], char *const envp[]) {
    return (int)__syscall3(sys_execve, (long)pathname, (long)argv, (long)envp);
}

pid_t waitpid(pid_t pid, int *wstatus, int options) {
    return (pid_t)__syscall4(sys_wait4, (long)pid, (long)wstatus, (long)options, 0);
}

int system(const char *command) {
    if (command == NULL) {
        return 1;
    }

    pid_t pid = fork(); 
    
    if (pid < 0) {
        return -1;
    } 
    else if (pid == 0) {

        char *argv[] = {"sh", "-c", (char *)command, NULL};
        char *envp[] = {NULL};
        
        execve("/bin/sh", argv, envp);
        
        __syscall1(sys_exit, 127); 
        return 127;
    } 
    else {
        int status = 0;
        waitpid(pid, &status, 0);
        return status;
    }
}