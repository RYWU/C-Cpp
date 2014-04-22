//
//  main.c
//  GCD of BigInt.c
//
//  Created by WILLIAM on 3/4/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
// idx [2][1][0]
// vlu  3  1  2

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int *scanNum();
void printNum(int *arr);
int compare(int *arr1, int *arr2);
int getDigit(int *arr);
void reverse(int *arr);
void swap(int *arr1, int *arr2);
int isZero(int *arr);
int *minus(int* arr1, int* arr2);
int *divTwo(int *arr);
int *times(int *arr, int time);
int *GBB(int *arr1, int *arr2);
int main(int argc, const char * argv[])
{
    int *array1 = scanNum();
    int *array2 = scanNum();
    int *array3 = GBB(array1, array2);
    printNum(array3);
    return 0;
}

int *scanNum(){
    int *array8 = (int *) malloc(101 * sizeof(int));
    char ch = 0;
    int i = 0;
    while (1) {
        ch = getchar();
        if (ch == ' '){
            break;
        }
        array8[i] = atoi(&ch);
        i++;
    }
    reverse(array8);
    return array8;
}
void printNum(int *arr){
    int i = 0;
    for (i = getDigit(arr)-1; i >= 0; i--){
        printf("%d", arr[i]);
    }
    printf("\n");
}
int compare(int *arr1, int *arr2){  // arr1 < arr2 = true;
    int i = 0;
    for (i = 100; i >= 0; i--){
        // !!!! 停在這 ！！！
        if (arr1[i] < arr2[i]){
            return 1;
        }else if (arr1[i] > arr2[i]){
            return 0;
        }else {
            continue;
        }
    }
    return -1;
}
int getDigit(int *arr){
    int i = 0;
    for (i = 100; i >= 0; i--){
        if (arr[i] != 0){
            return i+1;
        }
    }return 0;
}
void swap(int *arr1, int *arr2){
    int temp = 0;
    int i = 0;
    for (i = 0; i < 101; i++){
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}
int notZero(int *arr){
    int i = 0;
    for (i = 0; i < 101; i++){
        if (arr[i] != 0){
            return 1;// not zero
        }
    }
    return 0; // is zero
}
int *minus(int* arr1, int* arr2){ // arr1 - arr2
    int i = 0;
    int *arr3 = (int *)malloc(101 * sizeof(int));
    int carry = 0;
    for (i = 0; i < 101; i++){
        if (carry){
            arr1[i] -= 1;
            carry = 0;
        }
        if (arr1[i] - arr2[i] < 0){
            carry = 1;
            arr3[i] = 10 + arr1[i] - arr2[i];
        }else{
            arr3[i] = arr1[i] - arr2[i];
        }
    }
    return arr3;
}
int *divTwo(int *arr){
    int *arr4 = (int *)malloc(101 * sizeof(int));
    int digit = getDigit(arr);
    int i = 0;
    int carry = 0;
    for (i = digit-1; i >= 0; i--){
        if (carry){
            arr[i] += 10;
            carry = 0;
        }
        if(arr[i] % 2 == 1){
            arr4[i] = arr[i] / 2;
            carry = 1;
        }else{ // arr[i] even.
            arr4[i] = arr[i] / 2;
        }
    }
    return arr4;
}
int *times(int *arr, int time){
    int carry = 0;
    int i = 0;
    int *arr6 = malloc(101 * sizeof(int));
    for (i = 0; i < 101; i++){
        if (carry != 0){
            arr6[i] += carry;
            carry = 0;
        }
        if (arr[i] * time + arr6[i] >= 10){
            arr6[i] += (arr[i] * time) % 10;
            carry = (arr[i] * time + arr6[i]) / 10;
            if (arr6[i] >= 10){
                arr6[i] = arr6[i] % 10;
            }
        }else{
            arr6[i] += (arr[i] * time);
            if (arr6[i] >= 10){
                arr6[i] = arr6[i] % 10;
                carry = arr6[i] / 10;
            }
        }
    }
    return arr6;
}
int *GBB(int *arr1, int *arr2){ //arr1 > arr2;
    int ans = 1;
    while (notZero(arr1)==1 && notZero(arr2)==1) {
        if (arr2[0] % 2 == 0 && arr1[0] % 2 ==0){
            ans *= 2;
            //printf("ans*2\n");
            arr1 = divTwo(arr1);
            arr2 = divTwo(arr2);
            continue;
        }
        else if (arr2[0] % 2 == 0 && arr1[0] %2 == 1){
            arr2 = divTwo(arr2);
            continue;
        }
        else if (arr2[0] % 2 == 1 && arr1[0] %2 == 0){
            arr1 = divTwo(arr1);
            continue;
        }
        if (compare(arr1, arr2) == 1) {
            swap(arr1, arr2);
            //            printf("swap");
        }
        arr1 = minus(arr1, arr2);
        //        printf("minus\n");
    }
    printf("ans: %d\n", ans);
    printf("Final arr2:\n");
    printNum(arr2);
    
    return times(arr2, ans);
}
void reverse(int *arr){
    int i = 0;
    int temp = 0;
    for (i = 0; i < getDigit(arr)/2; i++){
        temp = arr[i];
        arr[i] = arr[getDigit(arr)-1-i];
        arr[getDigit(arr)-1-i] = temp;
    }
}