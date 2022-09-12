#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convert(long long int number, long long int in, long long int out){
        long long int tempNumber = number;
        if (number < 0)  { printf("Cannot convert"); return -1; }
        if (in > 10 || in < 2 || out > 10 || out < 2) { printf("Cannot convert"); return -1; }
        while(tempNumber != 0){
         if (tempNumber % 10 >= in) {printf("Cannot convert"); return -1;}
            tempNumber /= 10;
        }
        tempNumber = number;
    
       long long int convertedNumber = 0;
       long long int degree = 0; 
       while (tempNumber != 0){
        int rem = (tempNumber%10);
        convertedNumber+= rem*pow(in, degree);
        degree++;
        tempNumber/=10;
       } //from any to 10

        //printf("%d\n",convertedNumber);

        tempNumber = convertedNumber;
        convertedNumber = 0;
        degree = 1;

        while (tempNumber != 0)
        {
           convertedNumber+=(tempNumber%out)*degree;
           degree*=10;
           tempNumber/=out; 
        }//from 10 to any

        printf("res : %lld", convertedNumber);
    return 0;
}

int main () {
    long long int number;
    long long int in;
    long long int out;
    printf("Enter the number from to \n");
    scanf("%lld %lld %lld", &number, &in, &out);
    convert(number, in, out);
    return 0;

}