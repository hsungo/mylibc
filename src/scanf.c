#include "../include/stdio.h"

int refill(char *buf, int *idx, int *len){
    *len = __syscall3(sys_read, 0, (long)buf, BUFFER_SIZE);
    *idx = 0;
    return *len;
}

int scanf(const char *format, ...){
    char buf[BUFFER_SIZE];
    int cnt = 0, idx = 0, len;
    va_list args;
    va_start(args, format);

    if (refill(buf, &idx, &len) <= 0){
        return 0;
    }

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd': {
                    int *n = va_arg(args, int *);
                    int tmp = 0, sign = 1;

                    while (idx < len || refill(buf, &idx, &len) > 0) {
                        if (buf[idx] != ' ' && buf[idx] != '\n' && buf[idx] != '\t') break;
                        idx++;
                    }

                    if (buf[idx] == '-') {
                        sign = -1;
                        idx++;
                        if(idx == len){
                            refill(buf, &idx, &len);
                        }
                    }

                    while (buf[idx] >= '0' && buf[idx] <= '9') {
                        tmp = tmp * 10 + (buf[idx] - '0');
                        idx++;
                        if(idx == len){
                            if(refill(buf, &idx, &len) <= 0){
                                break;
                            }
                        }   
                    }

                    *n = tmp * sign;
                    cnt++;
                    break;
                }
                case 's':{
                    char *s = va_arg(args, char *);
                    
                    while (idx < len || refill(buf, &idx, &len) > 0) {
                        if (buf[idx] != ' ' && buf[idx] != '\n') break;
                        idx++;
                    }
                    
                    while (idx < len) {
                        if (buf[idx] == ' ' || buf[idx] == '\n' || buf[idx] == '\t') break;
                        *s++ = buf[idx++];
                        if (idx == len && refill(buf, &idx, &len) <= 0) break;
                    }
                    *s = '\0';
                    cnt++;
                    break;
                }
                case 'c':{
                    char *c = va_arg(args, char *);
                    if (idx < len || refill(buf, &idx, &len) > 0) {
                        *c = buf[idx++];
                        cnt++;
                    }
                    break;
                }
                default:
                    break;
            }
        } 
        format++;
    }

    va_end(args);
    return cnt;
}