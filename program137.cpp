#include<iostream>
using namespace std;

class Number
{
 public:  
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
};


int main()
{ 
    int iValue=0;
    int iRet=0;
    Number nobj;

    cout<<"Enter number\n";
    cin>>iValue;

    iRet=nobj.Fact(iValue);
    cout<<"Factorial is :"<<iRet<<endl;

    return 0;
}