#include<stdio.h>

void Display(char *str)
{ 
    if(*str!=0)
    {
        printf("%c\n",*str);
        Display(str++); //display(100) //display(100) ....
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