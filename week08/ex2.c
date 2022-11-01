#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
 void *p[10];
 struct rusage usage;
 for (int i = 0; i < 10; i++) {
    p[i] = malloc(10*1024*1024);   //after this operation in some peroid time there will not enough physical memory
    //Therefore si and so (I guess it is pageins and pageouts in MacOS) will increase, where si is the rate of swapping0-in memory from disk and so is swapping-out
    // memory to the disk 
    //But on my machine there is optimize swapping algotrithm and there is no need to use vitrual memory for current program
    memset(p[i], 0, 10 * 1024 * 1024);
    sleep(1);
 }

 for (int i = 0; i < 10; i++){
   free(p[i]);
 }
return 0;
}