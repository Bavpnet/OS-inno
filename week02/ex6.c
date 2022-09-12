#include <stdio.h>

int main(){
    int n = 0;
    printf("enter the number of lines \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            printf("%c", '*');
        }
        printf("%c", '\n');
    }

     printf("%c", '\n');

     int tempN = n;
     if (n%2 == 0) tempN/=2;
     if (n%2!=0) tempN = (n+1)/2;

        for (int i = 1; i <= tempN; i++){
        for (int j = 1; j <= i; j++){
            printf("%c", '*');
        }
         printf("%c", '\n');
        }
        for (int i = tempN - 1; i >= 1; i--){
        for (int j = i; j>=1; j--){
            printf("%c", '*');
        }
        printf("%c", '\n');
    }
      printf("%c", '\n');
    for (int i = 1; i <= n; i++){
        for (int j = 1; j<= n; j++)
        {
            printf("%c", '*');
        }
        printf("%c", '\n');
    }
     
    
}