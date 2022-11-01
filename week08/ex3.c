#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
 //allocate 10MB of memory
 void *p[10];
 struct rusage usage;
 for (int i = 0; i < 10; i++) {
    p[i] = malloc(10*1024*1024);   
    memset(p[i], 0, 10 * 1024 * 1024);
    sleep(1);
 }
 for (int i = 0; i < 10; i++){
   free(p[i]);
 }
return 0;  
}