#include<stdio.h>
#include<stdlib.h>

int Summation(int Arr[],int iNo)
{
  int iCnt=0;
  int iSum=0;

  for(iCnt=0;iCnt<iNo;iCnt++)
  {
      iSum=iSum+Arr[iCnt];
  }

  return iSum;

}
int main()
{
    int iSize=0;
    int iCnt=0;
    int iRet=0;
    int *iPtr=NULL;


    printf("Enter how many elements you want\n");
    scanf("%d",&iSize);
  
    iPtr=(int *)malloc(iSize*sizeof(int));

    printf("Enter elemts\n");

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        scanf("%d",&iPtr[iCnt]);
    }

    iRet=Summation(iPtr,iSize);
    
    printf("Sum is : %d\n",iRet);


    free(iPtr);


    return 0;
}