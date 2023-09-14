#include<iostream>

using namespace std;


class Number
{
    private:
      int no;   //characterstics

      public:
       void Accept()  //setter
       {
           cout<<"enter the value\n";
           cin>>this->no;
       }

       void Display() // getter
       {
           cout<<"Value is:"<<this->no<<endl;
       }

       int Factorial()
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
    Number nobj;
    int iRet=0;

    nobj.Accept();
    nobj.Display();

    iRet=nobj.Factorial();
    cout<<"factorial is:"<<iRet<<endl;

    return 0;
}