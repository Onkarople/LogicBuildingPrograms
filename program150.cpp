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
      int i=0,j=0;
      for(i=1;i<=iRow;i++)
      {
          for(j=1;j<=iCol;j++)
          {
              cout<<"*"<<"\t";
          }
          cout<<endl;
      }
   }
};


int main()
{
    pattern obj(4,4);
    obj.Display();

    return 0;
}


