//
//  main.c
//  Qsort a struct
//
//  Created by WILLIAM on 4/2/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//  QSort the Car by Car.time

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct car{
    char time[21];
    char plate[7];
    char station[7];
}Car;
int compare(const void *car1, const void *car2){ // 按照car的time做遞增排列。
    return strcmp( (*(const Car*)car1).time, (*(const Car*)car2).time );
}
int main(int argc, const char * argv[])
{
    Car data[1000000];
    qsort(data, 1000000, sizeof(Car), compare);
    
    return 0;
}

