#include <stdio.h>
#include <string.h>

int count(char word[256], char symbol){
        int count = 0;
       
        for (int i = 0; i < strlen(word) - 1; i++){
            if (word[i] == symbol) count++;
        }
        
        printf("%c:", symbol);
        return count;
    }

void countAll(char word[256]){
    for (int i = 0; i < strlen(word) - 1; i++){
        printf("%d", count(word, word[i]));
        if (i != strlen(word) - 2) {printf(", ");}
    }
}    
    
int main(){
    
    char word[256];
    printf("Enter a string: ");
    fgets(word, 256, stdin);
    for (int i = 0; i < strlen(word) - 1; i++){
        if (word[i] >= 65 && word[i] <= 90) word[i]+=32;
    }
    countAll(word);
    return 0;
}