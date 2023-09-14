#include<stdio.h>

int CountDigit(int iNo)
{
    int iCnt=0;
    int idigit=0;
    
    
    while(iNo!=0)
    {
        idigit=iNo%10;
        iCnt++;
        iNo=iNo/10;

    }

    return iCnt;

}



int main()
{
    int iValue=0;
    int iRet=0;


    printf("Enter number\n");
    scanf("%d",&iValue);

    iRet=CountDigit(iValue);

    printf("count is : %d\t ",iRet);


    return 0;
}