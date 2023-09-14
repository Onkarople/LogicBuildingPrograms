#include<stdio.h>
#include<stdlib.h>


void DisplayEven(int Arr[],int iLenth)
{
    int iCnt=0;
   
   printf("Even numbers are\n");
   for(iCnt=0;iCnt<iLenth;iCnt++)
    {
        
        if((Arr[iCnt])%2==0)
        {
           
           printf("%d\n",Arr[iCnt]);
        }
    }

}


int main()
{
   int iSize=0;
   int iCnt=0;
   int *iPtr=NULL;

   printf("Enter how many elements you want\n");
   scanf("%d",&iSize);

   iPtr=(int *)malloc(iSize*sizeof(int));

   printf("Enter elements\n");

   for(iCnt=0;iCnt<iSize;iCnt++)
   {
       scanf("%d",&iPtr[iCnt]);
   }

   DisplayEven(iPtr,iSize);


   free(iPtr);




    return 0;
}