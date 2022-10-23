#include "C:\Users\peder\OneDrive - Aarhus universitet\Programmering for Computerteknologi\Assignment 7\assignment-7-Daniel6702\include\taylor_sine.h"
//#include <stdio.h>
const double pi2 = 3.14159265358979323;

double factorial(int x) {
    double fact = 1;
    for (int i = 1; i <= x; i++) {
        fact *= i;
    }
    return fact;
}

double power(double x, int n) {
    double pow = 1;
    for (int i = 0; i < n; i++) {
        pow *= x;
    }
    return pow;
}

double taylor_sine(double x, int n) {
    if (x>pi2*2) {
        x -=  (int)(x/(pi2*2))*pi2*2; //removing excess angle (450 degree = 90 degree)
    }
    double result = 0;
    for (int i = 0; i < n; i++) {
        double y = power(x,2*i+1) / factorial(2*i+1); //calculating each link
        
       result = (i%2==0) ? result + y : result - y; //add link (y) to result alternating positive and neg
    }
    
    return result;
}


