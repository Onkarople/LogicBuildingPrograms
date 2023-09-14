#include<iostream>
using namespace std;

int CountWhiteSpace(char *str)
{
    int iCnt=0;
    while(*str!='\0')
    {
        if(*str==' ')
        {
            iCnt++;
        }
        str++;
    }

    return iCnt;
}

int main()
{
    char Arr[20];
    int iRet=0;

    cout<<"Enter String\n";
    cin.getline(Arr,20);


    iRet=CountWhiteSpace(Arr);

    cout<<"Count is"<<iRet;

    return 0;
}