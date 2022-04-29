#include "printk.h"

int vfprintk(FILE* fp, const char* format, va_list va){
    

    for(char* c = (char*)format; *c != '\0'; c++){
        if(*c == '%'){
            c++;
            if(*c == '\0'){
                break;
            }
            switch (*c)
            {
            case 'd':
                fprintf(fp ,"%d", va_arg(va, int));
                break;
            case 's':
                //printf("s' test = %lx", (long)test);
                fprintf(fp, "%s", va_arg(va, const char*)) ;
                break;
            case 'x':
                fprintf(fp, "%x", va_arg(va, int));
                break;
            case 'f':
                fprintf(fp, "%f", va_arg(va, double));
                break;
            case 'l':
                c++;
                if(*c == '\0'){
                    break;
                }
                if(*c == 'd'){
                    fprintf(fp, "%ld", va_arg(va, long));
                }
            default:
                fprintf(fp, "%c", *c);
                break;
            }
        }else{
            fprintf(fp, "%c", *c);
        }

    }
    return 0;
}

int fprintk(FILE* fp, const char* format, ...){
    int result;
    va_list va;

    va_start(va, format);
    result = vfprintk(fp, format, va);
    va_end(va);

    return result;
}

