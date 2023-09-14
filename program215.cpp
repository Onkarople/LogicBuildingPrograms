#include<iostream>

using namespace std;

template<class T>
T MaxNo(T Arr[],int size)
{
    int i=0;
    T Max=Arr[0];
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

    cout<<"max no is:"<<iRet<<endl;


    float Brr[]={10.11,20.10,30.21,40.44,50.51};
    float fRet=0.0;
    fRet=MaxNo(Brr,5);

    cout<<"max no is:"<<fRet<<endl;


    return 0;

}