//
//  main.c
//  GCD Analysis
//
//  Created by WILLIAM on 3/2/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//
#include <stdio.h>
int isEven(int num);
int isOdd(int num);
void swap(int *a, int *b);
int min(int a, int b);
int GCD(int a, int b);
int GBD(int a, int b);
int GBR(int a, int b);
int GBB(int a, int b);
int GBE(int a, int b);
int main(int argc, const char * argv[])
{
    int a = 0, b = 0;
    while (1) {
        scanf("%d", &a);
        if (a == 0) break;
        scanf("%d", &b);
        if ( b > a ){ // make a > b;
            swap(&a, &b);
        }
        int result = GCD(a, b);
        printf("Case (%d, %d): GCD-By-Def = %d, taking %d iterations\n", a, b, result, GBD(a, b));
        printf("Case (%d, %d): GCD-By-Reverse-Search = %d, taking %d iterations\n", a, b, result, GBR(a, b));
        printf("Case (%d, %d): GCD-By-Binary = %d, taking %d iterations\n", a, b, result, GBB(a, b));
        printf("Case (%d, %d): GCD-By-Euclid = %d, taking %d iterations\n", a, b, result, GBE(a, b));
        printf("\n");
    }
    return 0;
}
int isEven(int num){
    return num % 2 == 0;
}
int isOdd(int num){
    return num % 2 == 1;
}
int min(int a, int b){
    if (a < b){
        return a;
    }else{
        return b;
    }
}
void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int GCD(int a, int b){
    if ( b > a ){
        swap(&a, &b);
    }
    int temp = 0;
    while (a % b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}
int GBE(int a, int b){
    int temp = 0;
    int count = 0;
    while (a % b != 0) {
        temp = b;
        b = a % b;
        a = temp;
        count ++;
    }
    return count;
}
int GBD(int a, int b){
    int i = 0;
    int result = 0;
    int count = 0;
    for (i = 2; i <= min(a, b); i++){
        if (a % i == 0 && b % i == 0){
            result = i;
        }
        count ++;
    }
    return count;
}
int GBR(int a, int b){
    int i = 0;
    int count = 1;
    for (i = min(a, b); i >= 1; i--){
        if (a % i == 0 && b % i == 0){
            return count;
        }
        count++;
    }
    return 0;
}
int GBB(int a, int b){
    int ans = 1;
    int count = 0;
    while (b != 0 && a != 0) {
        if (isEven(b) && isEven(a)){
            ans = ans *2;
            a = a / 2;
            b = b / 2;
        }
        if (isEven(b) && isOdd(a)){
            b = b / 2;
        }
        if (isOdd(b) && isEven(a)){
            a = a / 2;
        }
        if (a < b){
            swap(&a, &b);
        }
        a = a - b;
        count++;
    }
    return count;
}
