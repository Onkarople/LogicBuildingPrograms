#include<stdio.h>

int Sum(int Arr[],int isize)
{
   
    static int iSum=0;
    if(isize>=0)
    {
        isize--;
        iSum=iSum+Arr[isize];
        Sum(Arr,isize);
       
    }

    return iSum;

}

int main()
{
    int Brr[]={10,20,30,40};
    int iRet=0;

    iRet=Sum(Brr,4);;

    printf("Summation is:%d\n",iRet);

    return 0;
}