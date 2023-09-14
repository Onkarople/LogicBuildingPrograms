#include<stdio.h>

int Sum(int Arr[],int isize)
{
    int i=0;
    int iSum=0;
    for(i=0;i<isize;i++)
    {
        iSum=iSum+Arr[i];
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