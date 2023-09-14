#include<iostream>

using namespace std;

void Display(int Arr[],int iSize)
{
    int iCnt=0;
    cout<<"elements are\n";
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";

    }

}

int main()
{
    int *ptr=NULL;
    int iSize=0;
    int iCnt=0;
   
    cout<<"Enter how many elements you want\n";
    cin>>iSize;

    ptr=new int[iSize];

    cout<<"enter elemnts \n";
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        cin>>ptr[iCnt];
    }

    Display(ptr,iSize);



   return 0;

}