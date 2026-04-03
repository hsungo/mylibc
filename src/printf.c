#include "../include/stdio.h"  

int printf(const char *format, ...){
    char buf[BUFFER_SIZE];
    int cnt = 0, idx = 0;
    va_list args;
    va_start(args, format);

    while(*format){
        if(*format == '%'){
            format++;
            switch (*format){
                case '%':
                    buf[idx++] = '%';
                    break;
                case 'd':
                    int n = va_arg(args, int);
                    if(n == 0){
                        buf[idx++] = '0';
                    }
                    if(n < 0){
                        buf[idx++] = '-';
                        n = -n;
                    }
                    char tmp[10];
                    int tmp_idx = 0;
                    while (n > 0) {
                        tmp[tmp_idx++] = (n % 10) + '0';
                        n /= 10;
                    }
                    while (tmp_idx > 0) {
                        buf[idx++] = tmp[--tmp_idx];
                            if(idx == BUFFER_SIZE) {
                            __syscall3(sys_write, 1, (long)buf, BUFFER_SIZE);
                            cnt += idx;
                            idx = 0;
                        }
                    }
                    break;
                case 'c':
                    char c = (char)va_arg(args, int);
                    buf[idx++] = c;
                    break;
                case 's':
                    char *s = va_arg(args, char*);
                    while(*s){
                        buf[idx++] = *s++;
                        if(idx == BUFFER_SIZE) {
                            __syscall3(sys_write, 1, (long)buf, idx);
                            cnt += idx;
                            idx = 0;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        else{
            buf[idx++] = *format; 
        }
        format++;
        if(idx == BUFFER_SIZE){
            __syscall3(sys_write, 1, (long)buf, BUFFER_SIZE);
            cnt += idx;
            idx = 0;
        }
    }

    if(idx > 0){
        __syscall3(sys_write, 1, (long)buf, idx);
        cnt += idx;
    }

    va_end(args);
    return cnt;
}
