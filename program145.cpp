//template
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

      
};

int main()
{
    Number nobj;
    int iRet=0;

    nobj.Accept();
    nobj.Display();

    

    return 0;
}