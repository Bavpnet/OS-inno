#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int main()
{
    clock_t c1 = clock();
    clock_t child_time;
    for (int i = 0; i < 2; i++)
    {

        if (fork() == 0)
        {
            child_time = clock();
            printf("child: id = %d; parent: id = %d; execution time = %f\n",
                   getpid(), getppid(), (float)(clock() - child_time) * 1000 / CLOCKS_PER_SEC);
            exit(0);
        }
    }
    while (wait(NULL) > 0)
        ;
    printf("parent: id = %d; parent: id = %d; execution time = %f\n",
           getpid(), getppid(), (float)(clock() - c1) * 1000 / CLOCKS_PER_SEC);

    return 0;
}