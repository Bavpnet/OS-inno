#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

const int MAX_SIZE = 120;

FILE *pFile;

void arrayInitialization(int u[], int v[])
{
    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0; i < MAX_SIZE; i++)
    {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
        //printf("[%d, %d]\n", u[i], v[i]);
    }
}
int dotprod(int u[], int v[], int start, int end)
{

    int result = 0;

    for (int i = start; i < end; i++)
    {
        result += u[i] * v[i];
    }

    return result;
}

void calculation()
{
    int u[MAX_SIZE];
    int v[MAX_SIZE];

    arrayInitialization(u, v);

    int n; // number of processes
    printf("enter the number of processes \n");
    scanf("%d", &n);
    int limStart = 0;
    int limEnd = 0;
    pFile = fopen("temp.txt", "w");

    for (int i = 0; i < n; i++)
    {
        pid_t p = fork();
        limStart = i * MAX_SIZE / n;
        limEnd = limStart + MAX_SIZE / n;

        if (p == 0)
        {
            int result = dotprod(u, v, limStart, limEnd);
            // printf("pid: %d - [%d,%d]\n", getpid(), limStart,limEnd);
            //printf("%d ", result);
            fprintf(pFile, "%d ", result);
            exit(0);
        }
    }
    fclose(pFile);
}

void readFromFile()
{
    pFile = fopen("temp.txt", "r");
    int sumProcess = 0;
    int sum = 0;

    while (fscanf(pFile, "%d", &sumProcess) != EOF)
    {
        sum += sumProcess;
    }
    printf("sum = %d\n", sum);
    fclose(pFile);
}
int main(int args, char *argv[])
{
    calculation();
    while (wait(NULL) > 0)
        ;
    readFromFile();
    return 0;
}