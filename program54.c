#include<stdio.h>
#include<stdbool.h>

 bool CheckPalindrome(int iNo)
{
  int iTemp=0;
  int iDigit=0;
  int iRev=0;

  if(iNo<0)
  {
      iNo=-iNo;
  }
     iTemp=iNo;

  while(iNo>0)
  {
      iDigit=iNo%10;
      iRev= iRev*10 + iDigit;
      iNo=iNo/10;
  }
 
   if(iRev==iTemp)
   {
       return true;
   }
   else
   {
       return false;
   }

 
}

int main()
{
  int iValue=0;
  bool bRet=false;

  printf("Enter number\n");
  scanf("%d",&iValue);


   bRet =CheckPalindrome(iValue);

    if(bRet==true)
     {
      printf("%d Number is palindrome\n",iValue);
     }
    else
     {
       printf("%d Number is not palindrome\n",iValue);
     }


    return 0;
}