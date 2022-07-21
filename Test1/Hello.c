#include "printk.h"

int main(int argc, char const *argv[])
{
    fprintk(stdout, "Hello World My System\n");
    for(int i = 0; i < 10; i++){
        fprintk(stdout,"%d\n",i);
    }
    return 0; 
}
