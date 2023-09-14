#include<stdio.h>


int SumDigit(int iNo)
{  
    int iDigit=0;
    int iSum=0;
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
    int iNo=0;
    int iRet=0;

    printf("Enter number\n");
    scanf("%d",&iNo);

    iRet=SumDigit(iNo);


    printf("Sum is:%d",iRet);


    return 0;


}