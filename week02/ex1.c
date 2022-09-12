#include <stdio.h>
#include <float.h>
#include <limits.h>

    int main(){

    int var1 = INT_MAX; 
    unsigned short int var2 = USHRT_MAX ;
    signed long int var3 = LONG_MAX ;
    float var4 = FLT_MAX;
    double var5 = DBL_MAX;

 
    printf ("size of int %ld, value %d \n", sizeof(var1), var1);
    printf ("size of short int %ld, value %hu \n", sizeof(var2), var2);
    printf ("size of long int %ld, value %li \n", sizeof(var3), var3);
    printf ("size of float %ld, value %f \n", sizeof(var4), var4);
    printf ("size of double %ld, value %lf \n", sizeof(var5), var5);

    return 0;
}