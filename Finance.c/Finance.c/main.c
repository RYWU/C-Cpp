//
//  main.c
//  Finance.c
//
//  Created by WILLIAM on 2/19/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    double result = 1;
    double rate = 0;
    
    double initValue = 0;
    printf("Enter the initValue: ");
    scanf("%lf", &initValue);
    
    printf("Enter the rate: ");
    scanf("%lf", &rate);
    
    double spotRate = 0;
    printf("The spot rate: ");
    scanf("%lf", &spotRate);
    
    //spot rate after 100 period is: 900909.
    
    int i = 0;
    for (i = 0; i < 100; i++){
        result *= rate;
    }
    printf("the rate after 100 period: %lf.\n", result);
    printf("the Value after 100 period is: %f\n", floor (result * initValue) );
    
    return 0;
}