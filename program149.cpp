/*
* * * *
* * * *
* * * * 
* * * *
iRow=4;
icol-=4;

*/
//template for pattern printing
#include<iostream>
using namespace std;

class pattern
{
   private:
   int iRow,iCol;

   public:
   pattern(int a,int b)
   {
       this->iRow=a;
       this->iCol=b;
   }   


    void Display()
   {

   }
};


int main()
{
    pattern obj();
    obj.Display();

    return 0;
}