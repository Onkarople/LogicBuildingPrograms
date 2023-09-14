#include<stdio.h>
#include<stdbool.h>

void DisplayF(int iNo)
{
    int icnt=0;
    for(icnt=1;icnt<=iNo;icnt++)
    {
        printf("%d\n",icnt);
    }
}

void DisplayB(int iNo)
{
    int iCnt=0;
    for(iCnt=iNo;iCnt>=1;iCnt--)
    {
        printf("%d",iCnt);
    }
}



int main()
{
  int iValue=0;
  

  printf("enter number\n");
  scanf("%d",&iValue);

  printf("forward Display\n");
  DisplayF(iValue);
  printf("backward Display\n");
  DisplayB(iValue);


  

   return 0;
}