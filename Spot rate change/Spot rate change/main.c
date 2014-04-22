//
//  main.c
//  Spot rate change
//
//  Created by WILLIAM on 3/5/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
/*
    Inputs: n (year), q (the n-year zero-coupon bond price as % of par), k (the increment in bond price, also as % of par). 
    Output: the change in the n-year spot rate in %.
    For example: assume n=10, q=60, k=1, then the change in the n-year spot rate is −1.9971%.
    
    In: 10 60 1
    Out: -1.9971 %

    In: 5 50 2
    Out: -3.0535 %
*/

#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[])
{
    printf("Input n: ");
    double n = 0;
    scanf("%lf", &n);
    
    printf("Input q: ");
    double q = 0;
    scanf("%lf", &q);
    
    printf("Input k: ");
    double k = 0;
    scanf("%lf", &k); // Read n, q, k.
    
    double r0 = 0;
    double r1 = 0;
    double result = 0;
    
    r0 = pow( (100 / q) , (1 / n) ) - 1;
    r1 = pow( (100 / q / (1+k/100)) , (1 / n)) - 1;
    result = (r1 - r0) / r0 * 100;
    
    printf("Spot rate change: %.4lf%% ", result);
    printf("© 吳瑞洋公司\n");
    return 0;
}