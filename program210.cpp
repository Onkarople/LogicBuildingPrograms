#include<iostream>
using namespace std;

int Addition(int A,int B)
{
   int Ans;

   Ans=A+B;

   return Ans;
}

int main()
{
    int iValue=11,iValu2=21;
    int iRet=0;
    iRet=Addition(iValue,iValu2);
    cout<<"Additon is"<<iRet<<endl;




    return 0;


}