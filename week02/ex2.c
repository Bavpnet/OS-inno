#include <stdio.h>
#include <string.h>
int main(){
    char inpt[256];
    char symbol = getchar();
    int count = 0;
    while (symbol != '\n' && symbol != '.'){
        inpt[count] = symbol;
        symbol = getchar();
        count++;
    }
    printf("%c", '\"');
    for (int i = count - 1; i >= 0; i--){
        printf("%c", inpt[i]);
    }
    printf("%c", '\"');
    return 0;
}