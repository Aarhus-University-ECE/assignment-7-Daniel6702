//#include "taylor_sine.c
#include "C:\Users\peder\OneDrive - Aarhus universitet\Programmering for Computerteknologi\Assignment 7\assignment-7-Daniel6702\include\taylor_sine.h"
#include <stdio.h>
#include <math.h>
const double pi = 3.14159265358979323;

//B
void test1(int precision) {
    printf("Taylor_sine:  sin(PI) = %f\n",taylor_sine(pi,precision)); //-0.000001
    printf("ANSI C sin:   sin(PI) = %f\n",sin(pi)); //0.000000

    printf("Taylor_sine:  sin(PI/4) = %f\n",taylor_sine(pi/4,precision)); //0.707107
    printf("ANSI C sin:   sin(PI/4) = %f\n",sin(pi/4));  //0.707107

    printf("Taylor_sine:  sin(PI/2) = %f\n",taylor_sine(pi/2,precision)); //1.000000
    printf("ANSI C sin:   sin(PI/2) = %f\n",sin(pi/2)); // 1.000000

    printf("Taylor_sine:  sin(PI*PI) = %f\n",taylor_sine(pi*pi,precision)); //-0.430308
    printf("ANSI C sin:   sin(PI*PI) = %f\n",sin(pi*pi)); //-0.430301
}

int main(int argc, char **argv)
{
    test1(4);
    printf("-----------\n");
    test1(6);
    printf("-----------\n");
    test1(8);
    printf("-----------\n");
    test1(100);
    printf("-----------\n");
    test1(400);

    //c (1): with a precision of "8", the two methods gave very similar outputs. 
    //In somecases (PI/4) were they exactly even, in others (pi*pi) the differece was 0.0016%
    //(2): When increasing the number of terms the resuslt came closer and closer to a certain point
    //where it seemed to stop improving. The calculation time also greatly increased.
    return 0;
}