#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>

int main() {
    char message[1024];
      mkfifo("/tmp/ex1", 0666);
    while(1) {
        int fd = open("/tmp/ex1", O_RDONLY);
        if (fd == -1) {
            printf("Error");
            return 1;
        }



        if(read(fd, message, sizeof(char) * 1024) == -1) {
            printf("Error");
            return 2;
        }
        printf("Received %s\n", message);
        fflush(stdout);
        close(fd);
    }
    return 0;
}
