#include<stdio.h>
#include<stdbool.h>



int SumFactors(int iNo)
{
   int iCnt=0;
   int iSum=0;
     

     if(iNo<0)
     {
         iNo=-iNo;
     }

    for(iCnt=1;iCnt<=(iNo/2);iCnt++)
    {
        if((iNo%iCnt)==0)
        {
            iSum=iSum+iCnt;

        }
    }

    return iSum;
    //PerfectNumber(iSum);

}


bool CheckPerfect(int iNo)

{
    int iAns=0;
    iAns=SumFactors(iNo);
    if(iAns==iNo)
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
  else{
      printf("%d is not perfect number",iValue);
  }


    return 0;
}