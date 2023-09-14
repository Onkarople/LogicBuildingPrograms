//input : 2   4
//Ouytput: 16

#include<stdio.h>

typedef unsigned long int ULONG;

ULONG Power(int iNo1,int iPower)
{
    int iCnt=0;
    ULONG lMult=1;

    for(iCnt=1;iCnt<=iPower;iCnt++)
    {
        lMult=lMult*iNo1;
    }

    return lMult;


}


int main()
{
   auto int iValue1=0;
   auto int iValue2=0;
   auto ULONG lRet=0;

   printf("Enter the number\n");
   scanf("%d",&iValue1);

   printf("Enter the power\n");
   scanf("%d",&iValue2);

  
    lRet=Power(iValue1,iValue2);

    printf("Result is \n %ld",lRet);

    return 0;
}