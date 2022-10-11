// implementationn shortest job algorithm
#include <stdlib.h>
#include <stdio.h>

#define N 100
struct Input
{
    char name;
    int at;
    int bt;
};
void waitTime(int numberOfProcess, struct Input input[], int waitingTime[], int turnAroundTime[])
{
    for (int i = 0; i < numberOfProcess; i++)
    {
        waitingTime[i] = turnAroundTime[i] - input[i].bt;
    }
}

void complTime(int numberOfProcesses, int turnAroundTime[], struct Input input[], int completionTime[])
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        completionTime[i] = 0;
    }
    completionTime[0] = input[0].bt + input[0].at;
    for (int i = 1; i < numberOfProcesses; i++)
    {
        for (int j = i + 1; j < numberOfProcesses; j++)
        {

            if (input[j].at <= completionTime[i - 1])
            {
                if (input[j].bt < input[i].bt)
                {
                    struct Input temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;

                    int wt = completionTime[j];
                    completionTime[j] = completionTime[i];
                    completionTime[i] = wt;
                }
            }
        }
        if (input[i].at < completionTime[i - 1])
        {
            completionTime[i] = completionTime[i - 1] + input[i].bt;
        }
        else
        {
            completionTime[i] = input[i].at + input[i].bt;
        }
    }
}

void turnATime(int numberOfProcesses, struct Input input[], int completionTime[], int turnAroundTime[])
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        turnAroundTime[i] = completionTime[i] - input[i].at; // TAT = ET - AT
    }
}

int compare1(const void *a, const void *b)
{
    struct Input *p1 = (struct Input *)a, *p2 = (struct Input *)b;
    if (p1->at == p2->at)
    {
        return p1->bt - p2->bt;
    }
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
    qsort(input, numberOfProcesses, sizeof(struct Input), compare1);
    complTime(numberOfProcesses, turnAroundTime, input, completionTime);
    turnATime(numberOfProcesses, input, completionTime, turnAroundTime);
    waitTime(numberOfProcesses, input, waitingTime, turnAroundTime);
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
