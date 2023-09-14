#include<stdio.h>

void Display(int No)
{ 
    
    static char ch='a';

    if(No>0)
    {
        printf("%c\t",ch);
        ch++;
        No--;
        Display(No);
    }
}

int main()
{
    int iNo=0;

    printf("enter number\n");
    scanf("%d",&iNo);

    Display(iNo);


    return 0;
}