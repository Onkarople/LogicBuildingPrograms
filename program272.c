#include<stdio.h>

void Display(int No)
{ 
    static int i=0;
    static char ch='a';

    if(i<No)
    {
        i++;
        Display(No);
        printf("%c\t",ch);
        ch++;
        
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