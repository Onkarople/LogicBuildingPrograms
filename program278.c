#include<stdio.h>

void Display(char *str)
{ 
    if(*str!=0)
    {
        Display(str+1);    //head recursion
        printf("%c\n",*str);
       
    }
    
}

int main()
{
    char Arr[20];

    printf("enter String\n");
    scanf("%[^'\n']s",Arr);

    Display(Arr); //Display(920)

    return 0;
}