//write a program to perform addition of 2 numbers
#include<stdio.h>

int Addition(int iValue1,int iValue2)
{ 
   int iAns=0;
   iAns=iValue1+iValue2;
   return iAns;

}
int main()
{
    int iNo1=0;
    int iNo2=0;
    int iNo3=0;

    printf("enterr first Number\n");
    scanf("%d",&iNo1);

    printf("Eneter second Number\n");
    scanf("%d",&iNo2);
    

    iNo3=Addition(iNo1,iNo2);

    printf("addition is %d\n",iNo3);

    return 0;
}