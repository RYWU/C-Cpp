//
//  main.c
//  美國國庫存底
//
//  Created by WILLIAM on 3/13/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//  這個程式產出36500筆數字。呈現常態分佈的數字。Normal distribution.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
int main(){
    double x = 0;
    double y = 0;
    double mean = 100000000000;//期望值。  1T
    double std = 94000000000;//標準差。   1T
    srand(time(NULL));
    FILE *fp;
	int i = 0;
    fp = fopen("balance.txt", "w");
    assert(fp != NULL);
    for (i = 0; i < 36500/2; i++){
        double u = (float)rand() / (float)RAND_MAX ;
        double v = (float)rand() / (float)RAND_MAX;
        x = sqrt(-2 * log(u)) * cos(2 * v * M_PI) * std + mean;
        y = sqrt(-2 * log(u)) * sin(2 * v * M_PI) * std + mean;
        fprintf(fp, "%ld\n",(long int) x);
        fprintf(fp, "%ld\n",(long int) y);
    }
    fclose(fp);
}