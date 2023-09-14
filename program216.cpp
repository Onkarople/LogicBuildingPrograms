#include<iostream>
using namespace std;

class Arrayx
{
   public:
      int *Arr;
      int size;

      Arrayx(int value)
      {
        size=value;
        Arr=new int[size];
      }

      ~Arrayx()
      {
        delete []Arr;
      }

     void Accpet()
     {
        cout<<"enter the values:"<<endl;
        for(int i=0;i<size;i++)
        {
            cin>>Arr[i];
        }
     }

     void Diplay()
     {
        cout<<"values are:";
        for(int i=0;i<size;i++)
        {
            cout<<Arr[i]<<endl;
        }
     }

};

int main()
{
     Arrayx obj1(5);

     obj1.Accpet();
     obj1.Diplay();

    


    return 0;

}