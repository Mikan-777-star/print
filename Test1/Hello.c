#include "printk.h"

int main(int argc, char const *argv[])
{
    fprintk(stdout, "Hello World My System\n");
    fprintk(stderr, "Hello World My Error Code\n");
    for(int i = 0; i < 100; i++){
        fprintk(stdout, "%d\n", i);
    }
    FILE* fp;
    fp = fopen("Test1.txt", "w");
    for(int i = 0; i < 100; i += 3){
        fprintk(fp, "%d\n", i);
    }
    fclose(fp);
    return 0; 
}
