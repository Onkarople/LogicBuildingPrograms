#include<iostream>
using namespace std;

template<class T>
void SwapR(T &p,T &q)
{
   T temp;
   temp=p;
   p=q;
   q=temp;
}


int main()
{
    int iNo1=11,iNo2=21;

    cout<<"Before swap data is :"<<iNo1<<" "<<iNo2<<endl;

    
   SwapR(iNo1,iNo2);

   cout<<"After swap data is :"<<iNo1<<" "<<iNo2<<endl;


    return 0;
}