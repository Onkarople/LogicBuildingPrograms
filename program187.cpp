#include<iostream>
using namespace std;

void strcpyX(char *src, char *dest )
{
  
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
    char Arr[20];  //bharleli wahi
    char Brr[20];  //kori wahi

    cout<<"Enter String\n";
    cin.getline(Arr,20);


     strcpyX(Arr,Brr);

    cout<<"String after copy is :"<<Brr<<endl;

    return 0;
}