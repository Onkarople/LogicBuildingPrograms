#include<stdio.h>


int SumDigit(int iNo)
{  
   
   static int iSum=0;
    if(iNo!=0)
    {
        iSum=iSum+(iNo%10);
        iNo=iNo/10;
        SumDigit(iNo);
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