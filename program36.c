#include<stdio.h>
#include<stdbool.h>

bool CheckPerfect(int iNo)
{
   int iCnt=0;
   int iSum=0;
     
     if(iNo<0)
     {
         iNo=-iNo;
     }

    for(iCnt=1;((iCnt<=(iNo/2)) && (iSum<=iNo));iCnt++)
    {
        if((iNo%iCnt)==0)
        {
            iSum=iSum+iCnt;

        }
        
    }

    if(iSum==iNo)
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
  //int iRet=0;
  bool bRet=false;

  printf("enter number");
  scanf("%d",&iValue);


  //iRet = SumFactors(iValue);
  bRet=CheckPerfect(iValue);
  //printf("sum of factotrs is %d",iRet);
  if(bRet==true)
  {
      printf("%d is perfect number",iValue);
  }
  else
  {
      printf("%d is not perfect number",iValue);
  }

   return 0;
}