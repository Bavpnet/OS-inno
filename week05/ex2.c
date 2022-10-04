#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
const int N = 5;
struct Thread
{
    int i;
    long id;
    char message[256];
} Thread;

void *printThread(void *p)
{
    struct Thread t = *((struct Thread *)p);
    t.id = pthread_self();
    printf(" i: %d \n id: %ld \n message: %s \n ", t.i, t.id, t.message);
    pthread_exit(NULL);
};
int main(int argc, char *argv[])
{
    pthread_t threads[4];
    int rc;
    int t;

    for (t = 0; t < N; t++)
    {
        printf("\n");
        struct Thread p;
        p.i = t;
        p.id = 0;
        char number[10];
        sprintf(number, "%d", t);
        char temp[256] = "Hello from thread ";
        strcpy(p.message, strcat(temp, number));
        rc = pthread_create(&threads[t], NULL, printThread, &p);
        printf(" Process %d is created!\n", t);
        pthread_join(threads[t], NULL);
    }
    pthread_exit(NULL);
    return 0;
}