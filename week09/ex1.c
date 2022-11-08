#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double aegingAlgorithm(int ref[], int frames[], int numberOfFrames, int count, int*miss, int*hit)
{
    int min, index, page_faults = 0;
    int age[numberOfFrames];
    int referenceBit[numberOfFrames];
    int present[numberOfFrames];

    for (int i = 0; i < numberOfFrames; i++)
    {
        age[i] = 0;
        referenceBit[i] = 0;
        present[i] = 0;
    }

    for (int i = 0; i < count; i++)
    {
        int flag = 0;
        for (int j = 0; j < numberOfFrames; j++)
        {
            if (frames[j] == ref[i])
            {
                flag = 1;
                *hit += 1;
                referenceBit[j] = 1;
                break;
            }
        }
        if (flag == 0)
        {
            *miss += 1;
            for (int j = 0; j < numberOfFrames; j++)
            {
                if (present[j] == 0)
                {
                    page_faults++;
                    frames[j] = ref[i];
                    age[j] = 0;
                    referenceBit[j] = 1;
                    present[j] = 1;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            min = INT_MAX;
            for (int j = 0; j < numberOfFrames; j++)
            {
                if (age[j] < min)
                {
                    min = age[j];
                    index = j;
                }
            }
            frames[index] = ref[i];
            age[index] = 0;
            referenceBit[index] = 1;
            page_faults++;
        }
        for (int j = 0; j < numberOfFrames; j++)
        {
            age[j] = age[j] >> 1;
            age[j] += referenceBit[j] * 128;
            referenceBit[j] = 0;
        }
    }
    return (double)*hit / (double)(*miss);
}

void input(int numberOfFrames){
    FILE *fp;
    int count = 1000;
    int ref[count];
    int *table;
    fp = fopen("Lab 09 input.txt", "r");
    for (int i = 0; i < count; i++){
        fscanf(fp, "%d", &ref[i]);
    }
    int frames[numberOfFrames];
    int miss = 0;
    int hit = 0;
    double hitRatio = aegingAlgorithm(ref, frames, numberOfFrames, count, &miss, &hit);   

    printf("Hits: %d\n", hit);
    printf("Misses: %d\n", miss);
    printf("Hit/Miss ratio:%f\n", hitRatio);

    fclose(fp);
    
}

int main(int args, char *argv[]){
    int numberOfPages;
    numberOfPages = atoi(argv[1]);
    input(numberOfPages);
    return 0;
}