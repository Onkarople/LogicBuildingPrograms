
#include<iostream>
using namespace std;

void strconcatX(char *src, char *dest )
{
  
    while(*dest!='\0')
    {
        dest++;
    }

    while(*src!='\0')
    {
        *dest=*src;
        src++;
        dest++;
    }
    
     *dest='\0';

}

int main()
{
    char Arr[20];  
    char Brr[20];  

    cout<<"Enter first String\n";
    cin.getline(Arr,20);

    cout<<"Enter second string\n";
    cin.getline(Brr,20);


     strconcatX(Arr,Brr);

    cout<<"String after concate is :"<<Brr<<endl;

    return 0;
}