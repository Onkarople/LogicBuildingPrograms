//input : 2   4
//Ouytput: 16

#include<stdio.h>

int Power(int iNo1,int iPower)
{
    register int iCnt=0;
    int iMult=1;

    for(iCnt=1;iCnt<=iPower;iCnt++)
    {
        iMult=iMult*iNo1;
    }

    return iMult;


}


int main()
{
   auto int iValue1=0;
   auto int iValue2=0;
   auto int iRet=0;

   printf("Enter the number\n");
   scanf("%d",&iValue1);

   printf("Enter the power\n");
   scanf("%d",&iValue2);

  
    iRet=Power(iValue1,iValue2);

    printf("Result is \n %d",iRet);

    return 0;
}