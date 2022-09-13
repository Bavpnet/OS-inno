#include <stdio.h>
#include <math.h>

long int Tribonacci (long int n){
    
    if (n == 0) return 0;
    if (n == 1 || n==2) return 1; 

    long int it1 = 0;
    long int it2 = 1;
    long int it3 = 1;
    long int trib = it1+it2+it3;

    for (int i = 3; i <= n; i++){
        trib = it1+it2+it3;
        it1 = it2;
        it2 = it3;
        it3 = trib;
    }
    
    return it3;
}

int main () {
    
    printf("%ld \n", Tribonacci(4));
    printf("%ld \n", Tribonacci(36));
    return 0;

}
