#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    typedef struct
    {
       float x;
       float y;
    } Point;

    float distance(Point A, Point B){
        return sqrt((A.x - B.x)*(A.x- B.x) + (A.y-B.y)*(A.y - B.y));
    }

    float area(Point A, Point B, Point C){
        return 0.5*fabsf(A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y);;
    }
    
int main (int argc, char *args[]){
    Point A = {2.5, 6};
    Point B = {1, 2.2};
    Point C= {10, 6};
   

    float f = distance(A, B);
	printf("A -- B distance is %f\n", f);


	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);
    return 0;
}