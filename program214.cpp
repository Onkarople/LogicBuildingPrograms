#include<iostream>

using namespace std;

int MaxNo(int Arr[],int size)
{
    int i=0;
    int Max=Arr[0];
    for(i=0;i<size;i++)
    {
         if(Max<Arr[i])
         {
            Max=Arr[i];
         }
    }

     return  Max; 
}


int main()
{
    int Arr[]={10,20,30,40,50};
    int iRet=0;
    iRet=MaxNo(Arr,5);

    cout<<"max no is:"<<iRet;


    return 0;

}