#include<stdio.h>

void Display(char *str)
{ 
    if(*str!=0)
    {
        printf("%s\n",str);
        Display(str+1);    //tail recurrsion
        
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