//tempalte on n numbers
#include<iostream>
using namespace std;


class Arryx
{

    private:
    int iSize;
    int *Arr;

    public :
     Arryx(int iValue)     //parametrised consturtor
    {
         this->iSize=iValue;
         Arr=new int[iSize];       //allocate the rescources
    }
      

    ~Arryx()                 // desctructor
    {
        delete []Arr;           //deallocate the resources
    }


    void Accept()
    {
        int iCnt=0;
        cout<<"enter the elemets"<<endl;
         for(iCnt=0;iCnt<iSize;iCnt++)
       {
          cin>>Arr[iCnt];
       }
    }

    void Display()
    {
        int iCnt=0;
        cout<<"Elemnts are\n";
        for( iCnt=0;iCnt<iSize;iCnt++)
        {
            cout<<Arr[iCnt]<<endl;
        }
    }

    

};


int main()
{
     int iRet=0;
     Arryx aobj(5);

     aobj.Accept();
     aobj.Display();
     
    return 0;
}