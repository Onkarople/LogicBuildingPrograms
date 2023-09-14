#include"Header59.h"

int main()
{
   auto int iValue1=0;
   auto int iValue2=0;
   auto ULONG lRet=0;

   printf("Enter the number\n");
   scanf("%d",&iValue1);

   printf("Enter the power\n");
   scanf("%d",&iValue2);

  
    lRet=Power(iValue1,iValue2);

    printf("Result is \n %ld",lRet);

    return 0;
}