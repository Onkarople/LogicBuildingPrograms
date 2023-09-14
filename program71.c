#include<stdio.h>
#include<stdlib.h>


int CountEven(int Arr[],int iLenth)
{
    int iCnt=0,iEvenCnt=0;
   

   for(iCnt=0;iCnt<iLenth;iCnt++)
    {
        
        if((Arr[iCnt])%2==0)
        {
           
          iEvenCnt++;
        }
    }

   return iEvenCnt;
}


int main()
{
   int iSize=0;
   int iCnt=0;
   int *iPtr=NULL;
   int iRet=0;

   printf("Enter how many elements you want\n");
   scanf("%d",&iSize);

   iPtr=(int *)malloc(iSize*sizeof(int));

   printf("Enter elements\n");

   for(iCnt=0;iCnt<iSize;iCnt++)
   {
       scanf("%d",&iPtr[iCnt]);
   }

  iRet= CountEven(iPtr,iSize);


  printf("Even count is : %d \n",iRet);


   free(iPtr);




    return 0;
}