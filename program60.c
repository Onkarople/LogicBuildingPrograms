#include<stdio.h>
#include<stdbool.h>

int Power(int iNo1,int iPower)
{
    register int iCnt=0;
    int iMult=1;

    for(iCnt=1;iCnt<=iPower;iCnt++)
    {
        iMult=iMult*iNo1;
    }

    return iMult;
}


bool ChkAmstrong(int iNo)
{
    
    int iDigit=0;
    int iTemp=0;
    int iSum=0;
    int iDigCnt=0;

    if(iNo<0)
    {
        iNo=-iNo;
    }

     iTemp=iNo;


    while(iNo!=0)  //calculate number of digit 
    {
         iDigCnt++;
         iNo=iNo/10;
    }

    iNo=iTemp;  //undo value of iNo

    while(iNo!=0)
    {
        iDigit=iNo%10;
        iSum=iSum+Power(iDigit,iDigCnt);
        iNo=iNo/10;
        
    }

    if(iSum==iTemp)
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


   printf("ENter number\n");
   scanf("%d",&iValue);


   bRet=ChkAmstrong(iValue);

   if(bRet==true)
   {
      printf("%d is Amostrong\n",iValue);
   }
   else
   {
      printf("%d is not \n",iValue);
   }



    return 0;
}