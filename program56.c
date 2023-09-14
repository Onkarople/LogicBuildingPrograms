//input : 2   4
//Ouytput: 16

#include<stdio.h>

long int Power(int iNo1,int iPower)
{
     int iCnt=0;
    long int lMult=1;

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
    long int lRet=0;

   printf("Enter the number\n");
   scanf("%d",&iValue1);

   printf("Enter the power\n");
   scanf("%d",&iValue2);

  
    lRet=Power(iValue1,iValue2);

    printf("Result is \n %ld",lRet);

    return 0;
}