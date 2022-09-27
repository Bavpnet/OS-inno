#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]){
   
    for (int i = 0; i < atoi(argv[1]); i++){        
       fork();
       sleep(5);
    }
}