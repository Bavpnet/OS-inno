#include <stdlib.h>
#include <stdio.h>

#define N 100

struct Input
{
    char name;
    int at;
    int bt;
};
void waitTime(int numberOfProcess, struct Input input[], int waitingTime[])
{
    int startingTime[N];
    startingTime[0] = input[0].at;
    waitingTime[0] = 0;

    for (int i = 1; i < numberOfProcess; i++)
    {
        startingTime[i] = startingTime[i - 1] + input[i - 1].bt;
        waitingTime[i] = startingTime[i] - input[i].at;
        if (waitingTime[i] < 0)
        {
            waitingTime[i] = 0;
        }
    }
}
void complTime(int numberOfProcesses, int turnAroundTime[], struct Input input[], int completionTime[])
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        completionTime[i] = input[i].at + turnAroundTime[i];
    }
}

void turnATime(int numberOfProcesses, struct Input input[], int waitingTime[], int turnAroundTime[])
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        turnAroundTime[i] = input[i].bt + waitingTime[i]; // TAT = BT + WT
    }
}
int compare(const void *a, const void *b)
{
    struct Input *p1 = (struct Input *)a, *p2 = (struct Input *)b;
    return p1->at - p2->at;
}
int main(int argc, char *argv[])
{
    int numberOfProcesses;
    printf("Enter number of processes: \n");
    scanf("%d", &numberOfProcesses);
    int waitingTime[N];
    int turnAroundTime[N];
    int completionTime[N];

    struct Input input[numberOfProcesses];

    printf("Enter arrival time for each process: \n");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        input[i].name = 'A' + i;
        scanf("%d", &input[i].at);
    }
    printf("Enter brust time for each process: \n");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        scanf("%d", &input[i].bt);
    }
    qsort(input, numberOfProcesses, sizeof(struct Input), compare);
    waitTime(numberOfProcesses, input, waitingTime);
    turnATime(numberOfProcesses, input, waitingTime, turnAroundTime);
    complTime(numberOfProcesses, turnAroundTime, input, completionTime);
    printf("\tArrival Time\t Burst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    int sumTurnAroundTime = 0, sumWaitingTime = 0;
    for (int i = 0; i < numberOfProcesses; i++)
    {
        sumTurnAroundTime += turnAroundTime[i];
        sumWaitingTime += waitingTime[i];
        printf("P %c| ", input[i].name);
        printf("\t%d\t\t|%d\t\t|%d\t\t|%d\t\t\t|%d\n", input[i].at, input[i].bt, completionTime[i], turnAroundTime[i], waitingTime[i]);
    }
    printf("Average turn around time = %f\n", (float)sumTurnAroundTime / numberOfProcesses);
    printf("Average waiting time = %f\n", (float)sumWaitingTime / numberOfProcesses);
    return 0;
}
