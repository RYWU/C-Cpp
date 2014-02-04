#include <stdio.h>
#include <stdlib.h>

   int main()
{
    int x = 9;

//    int n;//wayshu

    if (x/10==0)
    {//1way
        printf("Single: %d", x );
    }

    else if(x-100<0)
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
    {//4way
        printf("Hello");
    }


    return 0;
}



