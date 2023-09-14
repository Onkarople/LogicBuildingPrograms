#include<stdio.h>
#include<stdlib.h>

int Summation(int Arr[],int iSize)
{
     int iCnt=0;
     int iSum=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
         iSum=iSum+Arr[iCnt];

    }
    return iSum;
}

int main()
{
    int iValue=0;
    int *ptr=NULL;
    int iRet=0;
    int iCnt=0;

    printf("Enter how many elements\n");
    scanf("%d",&iValue);

    ptr=(int *)malloc(iValue*sizeof(int));
    printf("Enter values\n");

    for(iCnt=0;iCnt<iValue;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }


    iRet=Summation(ptr,iValue);

    printf("Sum is :%d",iRet);
 

    return 0;
}

