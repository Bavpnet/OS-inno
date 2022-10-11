#include <stdio.h>
#include <stdlib.h>

#define N 100
int j, allTime = 0;
int queue[N];
int time = 0, front = 0, rear = 0, queueCounter = 0;
struct Input
{
    char name;
    int at;
    int bt;
};

void pushQueue(int q)
{
    queue[rear++] = q;
}

int showTopQueue()
{
    return queue[front++];
}

void waitTime(int numberOfProcess, struct Input input[], int waitingTime[], int turnAroundTime[])
{
    for (int i = 0; i < numberOfProcess; i++)
    {
        waitingTime[i] = turnAroundTime[i] - input[i].bt;
    }
}

void checkElement(struct Input input[], int numberOfProcesses)
{
   while(input[j].at <= time && j < numberOfProcesses){
    queueCounter++;
    pushQueue(j++);
   }
}

void complTime(int numberOfProcesses, struct Input input[], int completionTime[], int numberOfQuantum)
{
    int temp[numberOfProcesses];
    int flag = 0;
    int count = 0;
    int p = 0;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        temp[i] = input[i].bt;
    }

    time = input[0].at;
    queueCounter = 1;
    pushQueue(j++);

    while (time <= allTime)
    {
        if (flag == 1 || queueCounter != 0)
        {
            if (flag == 0 && count == 0)
            {
                p = showTopQueue();
                count = 0;
                flag = 1;
            }
            temp[p]--;
            if (temp[p] == 0)
            {
                time++;
                count = 0;
                completionTime[p] = time;
                flag = 0;
                queueCounter--;
                checkElement(input, numberOfProcesses);
                continue;
            }
            count++;
            if (count == numberOfQuantum)
            {
                time++;
                count = 0;
                checkElement(input, numberOfProcesses);
                pushQueue(p);
                flag = 0;
            }
            else
            {
                time++;
                checkElement(input, numberOfProcesses);
            }
        }
        else
        {
            time++;
            checkElement(input, numberOfProcesses);
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

int compare(const void *a, const void *b)
{
    struct Input *p1 = (struct Input *)a, *p2 = (struct Input *)b;
    return p1->at - p2->at;
}

void calculateAllTime(struct Input input[], int numberOfProcesses, int copletionTime[], int turnAroundTime[], int waitingTime[], int numberOfQuantum)
{
    allTime = input[0].at + input[0].bt;
    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (allTime < input[i].at)
        {
            allTime = input[i].at;
        }
        allTime += input[i].bt;
    }

    complTime(numberOfProcesses, input, copletionTime, numberOfQuantum);
}

int main(int argc, char *argv[])
{
    int numberOfProcesses;
    int numberOfQuantum;
    printf("Enter number of processes: ");
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

    printf("Enter number of quantum: ");
    scanf("%d", &numberOfQuantum);

    qsort(input, numberOfProcesses, sizeof(struct Input), compare);

    calculateAllTime(input, numberOfProcesses, completionTime, turnAroundTime, waitingTime, numberOfQuantum);
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