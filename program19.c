//program to display 1 to 5 on screen 
//output 1  2   3   4   5

#include<stdio.h>

void Display()
{
   int icnt=0;

   for(icnt=1;icnt<=5;icnt++)
   {
       printf("%d\n",icnt);
   }
}



int main()
{
   Display();

    return 0;
}