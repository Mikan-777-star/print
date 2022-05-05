#include "printk.h"
#include "Writek.h"

int fprintk(FILE* fp, const char* format, ...){
    int result;
    va_list va;
    char s[1024];
    int size;

    va_start(va, format);
    size = vsprintf(s, format, va);
    va_end(va);
    if(size < 0){
        result = size;
    }else{
        result = Writek(fp->_fileno, s, size);
    }
    return result;
}