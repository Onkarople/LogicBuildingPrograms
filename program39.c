//accpet number and check number is prime or not

#include<stdio.h>
#include<stdbool.h>


bool CheckPrime(int iNo)
{
    int iCnt=0;
    bool bFlag=true;
    
    for(iCnt=2;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
           bFlag=false;
           break;
        }
    }
    
    return bFlag;
    
}

/*bool CheckPrime(int iNo)
{
    int iCnt=0;
    
    for(iCnt=2;iCnt<=iNo/2;iCnt++)
    {
        if(iNo%iCnt==0)
        {
           break;
        }
    }
    
    if(iCnt>iNo/2)
    {
        return true;
    }
    else
    {
        return false;
    }

    
    
}*/


int main()
{
    int iValue=0;
    bool bRet=false;


    printf("enter number\n");
    scanf("%d",&iValue);


    bRet=CheckPrime(iValue);
    if(bRet==true)
    {
        printf("Number is prime :%d\n",iValue);
    }
    else{
        printf("Number is not prime\n %d",iValue);
    }




    return 0;
}