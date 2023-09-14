#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Search(int Arr[],int iLength,int iNo)
{
  int iCnt=0;
  

   
   for(iCnt=0;iCnt<iLength;iCnt++)
     {
      
      if(Arr[iCnt]==iNo)
      {
          break;
      }
      
    }

    if(iCnt==iLength)
    {
        return false;
    }
    else
    {
        return true;
    }

   /*for(iCnt=0,iCnt1=iLength-1;iCnt<iLength,iCnt1>=0;iCnt++,iCnt1--)
     {
      
      if(Arr[iCnt]==iNo || Arr[iCnt1]==iNo) 
      {
          break;
      }
      
    }
    */


}
int main()
{
    int iSize=0,iValue=0;
    int iCnt=0;
    bool bRet=false;
    int *iPtr=NULL;


    printf("Enter how many elements you want\n");
    scanf("%d",&iSize);
  
    iPtr=(int *)malloc(iSize*sizeof(int));

   

    printf("Enter elements\n");

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        scanf("%d",&iPtr[iCnt]);
    }

    printf("Enter one number to search \n");
    scanf("%d",&iValue);
   
    bRet=Search(iPtr,iSize,iValue);
    
    if(bRet==true)
    {
        printf("Number is there\n");

    }
    else
    {
        printf("Number is not there\n");
    }


    free(iPtr);


    return 0;
}