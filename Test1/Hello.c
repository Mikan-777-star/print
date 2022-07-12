#include "printk.h"

int main(int argc, char const *argv[])
{
    fprintk(stdout, "Hello World My System\n");
    fprintk(stderr, "Hello World My Error Code\n");
    return 0; 
}
