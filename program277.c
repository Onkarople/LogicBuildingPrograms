#include<stdio.h>

void Display(char *str)
{ 
    if(*str!=0)
    {
        Display(++str);    //head recursion
        printf("%c\n",*str);
       
    }
    
}

int main()
{
    char Arr[20];

    printf("enter String\n");
    scanf("%[^'\n']s",Arr);

    Display(Arr);

    return 0;
}