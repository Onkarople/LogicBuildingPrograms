#include<stdio.h>

void Display(int No)
{ 
    int i=0;
    char ch='a';
    while(i<No)
    {
        printf("%c\t",ch);
        ch++;
        i++;
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