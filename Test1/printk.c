#include "printk.h"
#include "Writek.h"


char s[1024];

int fprintk(FILE* fp, const char* format, ...){
    int result;
    va_list va;
    int size;

    va_start(va, format);
    size = vsprintf(s, format, va);
    va_end(va);
    if(size < 0){
        result = size;
    }else{

        result = Writek(fp->_fileno, s, size);
        for(int i = 0; i < 100 ; i++){
            if(result == 0){
                break;
            }
            result = Writek(fp->_fileno, s, size);
        }
    }
    return result;
}