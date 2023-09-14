#include<stdio.h>
#include<stdlib.h>

void Display(int Arr[],int iLength)
{
    int iCnt=0;
    

   printf("Elemnts are :\n");
 
   for(iCnt=0;iCnt<iLength;iCnt++)
   {
     printf("%d\n",Arr[iCnt]);
     
   } 

}

int main()
{
   auto int iSize=0;
   //auto int Brr[iSize];
   int *iPtr=NULL;
   register int iCnt=0;

   printf("Enter how many elements you want\n");
   scanf("%d",&iSize);

   iPtr=(int *)malloc(iSize*sizeof(int));


   printf("enter elements\n");

   for(iCnt=0;iCnt<iSize;iCnt++)
   {
     scanf("%d",&iPtr[iCnt]);
   }
 
    Display(iPtr,iSize);

    free(iPtr);
   

    return 0;
}