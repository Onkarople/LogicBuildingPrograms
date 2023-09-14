#include<stdio.h>

int CountSmall(char *str)
{
     int icnt=0;
    while(*str!='\0')
    {
        if(*str>='a' &&  *str<='z')
        {
             icnt++;
        }
        str++;
    }
    return icnt;
}


int main()
{
   char Arr[20];
   int iRet=0;


   printf("Eneter string\n");
   scanf("%[^'\n']s",Arr);

   iRet=CountSmall(Arr);


   printf("Small charcterstics are :%d",iRet);


    return 0;
}