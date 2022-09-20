#include <stdio.h>
#include <stdlib.h>
int foo(int age){
        return 2022 - age;
    }

int main (int argc, char *args[]){
    const int x = 10;
    int *q = (int *)&x;
   // printf("%p", q);

    const int* const p1 = (const int*)malloc(5 * sizeof (int));
    int *p = p1;
    printf("Enter the years of birth: \n");
    for (int i = 0 ; i < 5; i++){
        int age;
        scanf("%d", &age);
        *(p + i) = age;
        printf(" memory = %p\n", (p+i)); //print memory adresses of alocated memory
        printf(" age = %d " , *(p+i)); //print age
        *(p + i) = foo(age);
        printf ("year = %d \n", *(p +i) ); //print date of birth
    }

    free(p1);
    
    return 0;
}