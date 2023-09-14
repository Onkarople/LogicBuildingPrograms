//program to display 1 to 5 on screen 
//output 1  2   3   4   5

#include<stdio.h>

void Display(int iNo)
{

   int icnt=0;
   if(iNo<0)
   {
       iNo=-iNo;
   }

   for(icnt=1;icnt<=iNo;icnt++)
   {
       printf("%d\n",icnt);
   }
}

int main()
{
   int iValue=0;
   printf("ENter the number\n");
   scanf("%d",&iValue);

   Display(iValue);

    return 0;
}