#include<stdio.h>

int SumDigit(int iNo)
{
    int iSum=0;
    int iDigit=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    
    while(iNo!=0)
    {
        iDigit=iNo%10;
        
        iSum=iSum+iDigit;
        
        iNo=iNo/10;

    }

    return iSum;

}



int main()
{
    int iValue=0;
    int iRet=0;


    printf("Enter number\n");
    scanf("%d",&iValue);

    iRet=SumDigit(iValue);

    printf("sum is : %d\t ",iRet);


    return 0;
}