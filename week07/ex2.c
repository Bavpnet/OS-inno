#include <stdio.h>
#include <stdlib.h>
int main(){
    int number = 0;
    printf("Enter a number: \n");
    scanf("%d", &number);
    int *array = (int*)malloc(number * sizeof(int));
    printf("Array of numbers: \n");
    for (int i = 0; i < number; i++){
        array[i] = i;
    }
    for (int i = 0; i < number; i++){
        printf("%d ", array[i]);
    }
    free(array);
}