// http://palcourse.csie.ntu.edu.tw/testgirl/problem/c2011/homework/assignment01/DecodeCal.htm
//  main.c
//  DecodeCal.htm
//
//  Created by William on 9/7/13.
//  Copyright (c) 2013 WWU. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x = 4214;
    scanf("%d", &x);
    
//    int n;//wayshu
    
    if (x/10==0)
    {//1way
        printf("Single: %d", x );
    }
    
    else if(x/100==0)
    {//2way
        printf("Single: %d", x );
    }
    
    else if (x/1000==0)
    {//3way:amb
        
        if ( x%100<10 )//m==0
        {printf("Addition: %d", (x/100)+(x%10)  );//a+b
        }
        
        else if ( 10<=x%100<=19 )//m==1
        {printf("Subtraction: %d",(x/100)-(x%10) );}

        else {printf("Single: %d", x);}
    }

    else
    {//4way:cdef
        if (x%1000-x%100<100/*d==0*/ && x%100>=20) {printf("Addition: %d",x/1000+x%100);}//d==0&e!=0,1
        
        else if (190>=x%1000-x%10 && x%1000-x%10>=120) {printf("Subtraction: %d",x/1000-x%100);}//d==1&e!=0,1
        
        else if (x%100<10 && x%1000-x%100>=200) {printf("Addition: %d", x/100+x%10);}//e==0&d!=0,1
        
        else if (19>=x%100 && x%100>=10) {printf("Subtraction: %d", x/100-x%10);}//e==1&d!=0,1
        
        else if (x%100>=20 && x%1000>200) {printf("Single: %d", x);}//d!=1,0 & e!=1,0
        
        else {printf("Ambiguous: %d",x );}
    }
    
    
    return 0;
}

