#include<iostream>
using namespace std;

int CountVowels(char *str) //case sensative
{
    int iCnt=0;
    while(*str!='\0')
    {
        if(*str=='a' || *str=='e' || *str=='i'|| *str=='o' || *str=='u')
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


    iRet=CountVowels(Arr);

    cout<<"Count of Vowels  is:"<<iRet;

    return 0;
}