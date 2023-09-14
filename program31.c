//problems on number
//accept number and display the factor

//input=10
//output=1 2 5

//input=9
//output=3 

//input=-20
//output=1 2 4 5 10

//input=17
//output=1

#include<stdio.h>

void DisplayNonFactors(int iNo)
{
    int iCnt=0;
    if(iNo<0)
    {
         iNo=-iNo;

    }

     for(iCnt=1;iCnt<iNo;iCnt++)
     {
         if((iNo%iCnt)!=0)
         {
             printf("%d ",iCnt);
         }
       
     }
}

int main()
{

  int ivalue=0;

  printf("ENter number\n");
  scanf("%d",&ivalue);

  DisplayNonFactors(ivalue); 

    return 0;
}



//TIme complesity : O(N/2): order of n/2
//BigO- concept invent- noation
//omega