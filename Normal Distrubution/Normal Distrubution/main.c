//
//  main.c
//  Normal Distrubution
//
//  Created by WILLIAM on 3/12/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.

//  公式：
//  x=跟號(-2*ln(u))*cos(2*pi*v)
//  y=跟號(-2*ln(u))*sin(2*pi*v)
//  u, v是(0,1)間的隨機小數。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
int main(){
    double x = 0;
    double y = 0;
    double mean = 0;//期望值。  1T
    double std = 10;//標準差。   1T
    srand(time(NULL));
	int i = 0;
    for (i = 0; i < 100; i++){
        double u = (float)rand() / (float)RAND_MAX ;
        double v = (float)rand() / (float)RAND_MAX;
        x = sqrt(-2 * log(u)) * cos(2 * v * M_PI) * std + mean;
        y = sqrt(-2 * log(u)) * sin(2 * v * M_PI) * std + mean;
        printf("%lf\n%lf\n", x, y);
    }
}
