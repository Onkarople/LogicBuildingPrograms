#include<stdio.h>

void Display(int No)
{ 
    int i=0;
    char ch='a';
    for(i=0;i<No;i++)
    {
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