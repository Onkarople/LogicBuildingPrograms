#include<iostream>
using namespace std;

template<class T>
T Addition(T A,T B)
{
   T Ans;

   Ans=A+B;

   return Ans;
}

int main()
{
    int iValue=11,iValu2=21;
    int iRet=0;
    iRet=Addition(iValue,iValu2);
    cout<<"Additon is:"<<iRet<<endl;


    float fValue=11.11,fValu2=21.11;
    float fRet=0.0;
    fRet=Addition(fValue,fValu2);
    cout<<"Additon is:"<<fRet<<endl;




    return 0;


}