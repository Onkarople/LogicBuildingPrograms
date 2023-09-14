#include<iostream>
using namespace std;

int Fact(int no)
{
    int iFact=1;
    int iCnt=0;
    for(iCnt=1;iCnt<=no;iCnt++)
    {
        iFact=iFact*iCnt;

    }
    return iFact;
}

int main()
{ 
    int iValue=0;
    int iRet=0;

    cout<<"Enter number\n";
    cin>>iValue;

    iRet=Fact(iValue);
    cout<<"Factorial is :"<<iRet<<endl;

    return 0;
}