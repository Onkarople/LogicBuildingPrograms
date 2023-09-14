#include<iostream>
using namespace std;

void struprX(char *str)
{
    int iCnt=0;
    while(*str!='\0')
    {
        if(*str>='a'&& *str<='z')
        {
            *str=*str-32;
        }
        str++;
    }
}

int main()
{
    char Arr[20];

    cout<<"Enter String\n";
    cin.getline(Arr,20);


     struprX(Arr);

    cout<<"String in upper case is :"<<Arr<<endl;

    return 0;
}