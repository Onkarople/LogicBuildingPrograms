#include<stdio.h>

int FactorialR(int no)
{
    static int iFact=1;

    if(no>0)
    {
        iFact=iFact*no;
        no--;
        FactorialR(no);
    }
    return iFact;
}

int main()
{
   int iNo=0;
   int iRet=0;

   printf("Enter the number\n");
   scanf("%d",&iNo);

   iRet=FactorialR(iNo);

   printf("Factorial is:%d",iRet);

    return 0;
}