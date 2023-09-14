//accpet number and check number is prime or not

#include<stdio.h>
#include<stdbool.h>

int CountFactor(int iNo)
{
    int iCnt=0;
    int iFactCnt=0;
    for(iCnt=2;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iFactCnt++;
        }
    }
    return iFactCnt;
}

bool CheckPrime(int iNo)
{
    int iAns=0;
    iAns=CountFactor(iNo);
    if(iAns==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iValue=0;
     bool iRet=false;


    printf("enter number\n");
    scanf("%d",&iValue);


    iRet=CheckPrime(iValue);
     
    if(iRet==true)
    {
        printf("Number is prime:%d\n",iValue);
    }
    else{
        printf("number is not prime:%d\n",iValue);
    }



    return 0;
}