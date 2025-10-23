//#include "taylor_sine.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

/* Compute the factorial of a given number. */
int fact(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
return result;

}

/*
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */
double taylor_sine(double x, int n)
{
    // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series

    double PI=3.14159265358979;
    int negative=1;
    while (x>PI){
        x=x-PI;
        negative*=-1;
    }
    while(x<0){
        x=x+PI;
        negative*=-1;
    }
    double result=0;
    int sign=1;
    for(int i=0;i<n;i++){
        int exponent = 2 * i + 1;
        double term = pow(x, exponent) / fact(exponent);
        result = result + (term*sign);
        sign *=-1;
    }
    result*=negative;
    return result; 
}

