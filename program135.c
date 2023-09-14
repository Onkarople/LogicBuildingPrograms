#include<stdio.h>


int Fact(int no)
{
    int iFact=1;
    int iCnt=0;
    for(iCnt=1;iCnt<=no;iCnt++)
    {
        iFact*=iCnt;

    }
    return iFact;
}

int main()
{ 
    int iValue=0;
    int iRet=0;

    printf("Enter number\n");
    scanf("%d",&iValue);

    iRet=Fact(iValue);
    printf("Factorial is :%d\n",iRet);

    return 0;
}