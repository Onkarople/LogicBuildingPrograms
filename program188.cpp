
#include<iostream>
using namespace std;

void strconcatX(char *src, char *dest )
{
  
    while(*src!='\0')
    {
        src++;
    }

    while(*dest!='\0')
    {
        *src=*dest;
        src++;
        dest++;
    }
    
     *src='\0';

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

    cout<<"String after concate is :"<<Arr<<endl;

    return 0;
}