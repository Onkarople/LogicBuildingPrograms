#include<stdio.h>
#include<stdlib.h>

int SearchLastOccurance(int Arr[],int iLength,int iNo)
{
  int iCnt=0;
   
   

   for(iCnt=iLength-1;iCnt>=0;iCnt--)
     {
      
      if(Arr[iCnt]==iNo)
      {
          break;   
      }
      
    }

     return iCnt;

}
int main()
{
    int iSize=0,iValue=0;
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

    printf("Enter one number\n");
    scanf("%d",&iValue);
   
    iRet=SearchLastOccurance(iPtr,iSize,iValue);
    
    if(iRet==-1)
    {
        printf("There is no such element\n");

    }
    else
    {
      printf("element last occurred at: %d\n",iRet);
    }

    free(iPtr);


    return 0;
}