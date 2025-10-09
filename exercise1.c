/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */
 
//#include "taylor_sine.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

/* Compute the factorial of a given number. */
int fact(int n)
{
    int f;
    int g; /* previous factorial */
    int i; /* counter variable for factorial */
    int j; /* counter variable for multiplication */
    /* precondition */
    assert(n >= 0);

    /* postcondition */
    g = 1;
    f = 1;
    for (i = 0; i < n; i = i + 1)
    { /* invariant: f equals factorial of i
         *            0 <= i <= n
         */
        for (j = 0; j < i; j = j + 1)
        { /* invariant: g = (j + 1) * f
           *            0 <= j <= i 
           */
            g = g + f;
        }
        f = g;
    }
return f;
}

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */
double taylor_sine(double x, int n) {
    // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series
    double svar=0;
    int skifter=1;
    int i2=1;
    for(int i=0;i<n;i++){
        double place=pow(x,i2)/fact(i2);
        svar=svar+(skifter*place);
        skifter=skifter*-1;
        i2=i2+2;
    }
    return svar; // placeholder - replace with your implementation
}
//int main(void){
  //  printf("\n%lf",taylor_sine(6.0,5));
//}
