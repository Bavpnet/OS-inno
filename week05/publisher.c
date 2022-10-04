#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>


int main(int args, char* argv[]) {
    int n = atoi(argv[1]);
    char arr[1024];
    int fd;
    mkfifo("/tmp/ex1", 0666);
    while(1) {
        printf(">> ");
        fgets(arr, 1024, stdin);
        fd  = open("/tmp/ex1", O_WRONLY);
        if (fd == -1) {
            printf("Error \n");
            return 1;
        }

        // We have opened the fifo 
        // for reading from another process
        // so we can write to it
        for (int i = 0; i < n; i++){
            if((write(fd, arr, sizeof(char)*1024) == -1)) {
                printf("Error");
                return 2;
            }
        }
        
        close(fd);
        sleep(2);
    }
    return 0;
}