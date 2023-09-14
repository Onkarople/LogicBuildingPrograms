#include<iostream>
using namespace std;

template<class T>
class Arrayx
{
   public:
      T *Arr;
      int size;

    Arrayx(int value);
    ~Arrayx();
    void Accpet();
    void Diplay();
    T Maximum();

};

template<class T>
Arrayx<T>::Arrayx(int value)
{
    size=value;
    Arr=new T[size];
}

template<class T>
Arrayx<T>::~Arrayx()
{
    delete []Arr;
}

template<class T>
void Arrayx<T>::Accpet()
{
    cout<<"enter the values:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void Arrayx<T>::Diplay()
{
    cout<<"values are:";
    for(int i=0;i<size;i++)
    {
        cout<<Arr[i]<<endl;
    }
}

template<class T>
T Arrayx<T>::Maximum()
{
    T Max=Arr[0];
    for(int i=0;i<size;i++)
    {
        if(Arr[i]>Max)
        {
            Max=Arr[i];
        }
    }
    return Max;
}



int main()
{
     Arrayx <int>obj1(5);
     obj1.Accpet();
     obj1.Diplay();
     int ret=obj1.Maximum();
     cout<<"Maximum is:"<<ret<<endl;


     Arrayx <float>obj2(5);
     obj2.Accpet();
     obj2.Diplay();
     float fret=obj2.Maximum();
     cout<<"Maximum is:"<<fret<<endl;
    


    return 0;

}