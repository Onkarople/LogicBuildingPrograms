//accpet number and check number is prime or not

#include<stdio.h>
#include<stdbool.h>

int CountFactor(int iNo)
{
    int iCnt=0;
    int iFactCnt=0;
    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iFactCnt++;
        }
    }
    return iFactCnt;
}

int main()
{
    int iValue=0;
    int iRet=0;


    printf("enter number\n");
    scanf("%d",&iValue);


    iRet=CountFactor(iValue);
     
     printf("Number of factors are : %d" ,iRet);
     return 0;




    return 0;
}