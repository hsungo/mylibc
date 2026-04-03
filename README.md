![C](https://img.shields.io/badge/Language-C-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

# mylibc

## Overview
freestanding implementation of the C standard library (`libc`)

---

## Project Structure

```text
mylibc/
├── include/                 
│   ├── stddef.h             # NULL, pid_t, size_t
│   ├── stdio.h              # printf, scanf
│   ├── stdlib.h             # system, malloc, free
│   ├── string.h             # strlen, memcpy, memset
│   ├── sys/                
│   │   └── syscall.h        # Syscall definitions
│   └── unistd.h             # fork, execve, waitpid, brk, sbrk
├── src/                     # implementations
│   ├── crt.c                # C Runtime startup (_start entry point)
│   ├── internal/            
│   │   ├── brk.c            # sbrk implementation for malloc
│   │   └── syscall.c        # inline assembly syscall
│   ├── malloc.c             
│   ├── printf.c             # %d, %c, %s only        
│   ├── process.c            
│   ├── scanf.c              # %d, %c, %s only          
│   └── string/             
│       ├── memcpy.c        
│       ├── memset.c
│       └── strlen.c
└── test/                   
    ├── Makefile          
    ├── syscall.txt          # list of x86_64 syscall numbers
    └── test.c               # for test function
```

## Getting Started
### Prerequisites
  * `gcc`、`make`
### Building
* #### quick start
```bash
git clone https://github.com/hsungo/mylibc.git
cd mylibc/test
make run
```

