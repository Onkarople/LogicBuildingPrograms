

#include<stdio.h>


void Display(int iRow,int iCol)
{
    int iCnt1=0;
    int iCnt2=0;
      
   
     for(iCnt1=1;iCnt1<=iRow;iCnt1++) //outer
      {
          
          for(iCnt2=1;iCnt2<=iCol;iCnt2++) //Inner
          {
              printf("*\t");
          }
          printf("\n");
                
      }

        
      
}

int main()
{
  int iValue1=0;
  int iValue2=0;

  printf("Enter rows\n");
  scanf("%d",&iValue1);

  printf("Enter coloumns\n ");
  scanf("%d",&iValue2);


  Display(iValue1,iValue2);


  return 0;
}