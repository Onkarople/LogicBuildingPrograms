#include<iostream>

using namespace std;

void Display(int Arr[],int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        cout<<Arr[i]<<endl;
    }
}


int main()
{
    int Arr[]={10,20,30,40,50};

    int *ptr=NULL;
    int size=0;

    ptr= new int[size];
    

    Display(Arr,5);


    return 0;

}