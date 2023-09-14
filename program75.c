#include<stdio.h>
#include<stdlib.h>

int Minimum(int Arr[],int iNo)
{
  int iCnt=0;
  int iMin=Arr[iCnt];
   
   

   for(iCnt=0;iCnt<iNo;iCnt++)
     {
      
      if(Arr[iCnt]<iMin)
      {
          iMin=Arr[iCnt];
      }
    }

  return iMin;

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

    iRet=Minimum(iPtr,iSize);
    
    printf("Min No is : %d\n",iRet);


    free(iPtr);


    return 0;
}