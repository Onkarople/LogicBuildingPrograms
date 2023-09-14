#include<stdio.h>

//4
//4*3*2*1=24

int FactorialI(int no)
{
    auto int iFact=1;

    while (no>0)
    {
        iFact=iFact*no;
        no--;
    }

    return iFact;
    
}

int main()
{
   int iNo=0;
   int iRet=0;

   printf("Enter the number\n");
   scanf("%d",&iNo);

   iRet=FactorialI(iNo);
   printf("Factorial is:%d",iRet);


    return 0;
}