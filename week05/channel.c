#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main() {
   while (1){
    int fd[2];
    // fd[0] - read end
    // fd[1] - write end
    if(pipe(fd) == -1) { 
        printf("Error");
        return 1;
    };
    int id = fork();
    if (id == 0) { // create publisher process
       
        close(fd[0]);
        char input[1024];
        printf("Write into the string\n");
        fgets(input, 1024, stdin);
        if (write(fd[1], input, sizeof(char)*1024) == -1){
            printf("Error, can not write into file\n");
        }
        close(fd[1]);
    } else { // subscriber process
       if (close(fd[1]) < 0) {
            printf("Error, can not close file\n");
        };
        char getInput[1024];
        
        if (read(fd[0], getInput, sizeof(char)*1024) == -1){
            printf("Error, can not read message \n");
        }  
        close(fd[0]);
        printf("Recieved message: %s", getInput);
        wait(NULL);
        kill(id, SIGKILL);
    }  
    }
    return 0;
}