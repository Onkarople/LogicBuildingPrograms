#include<stdio.h>

void JwelersPortal(int iWeight)
{ 
    switch(iWeight)
    {
        case 1 :
           printf("bill amount  is 4000\n");
           break;

       case 2 :
            printf("bill amount  is 8000\n");
            break;

       case 5 :
            printf("bill amount is 20000\n ");
            break;

        case 10 :
             printf("price is 40000\n");
             break;

        default:
            printf("inavlid weight\n");
            break;

    }

}

int main()
{
  int iGram=0;

  printf("enter the gold coin size that you want to purchase\n");
  printf("1 gram\n");
  printf("2 gram\n");
  printf("5 gram\n");
  printf("10 gram\n");


  scanf("%d",&iGram);
  
  JwelersPortal(iGram);

    return 0;
}