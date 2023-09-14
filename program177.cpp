#include<iostream>
using namespace std;

int CountCapital(char *str)
{
    int iCnt=0;
    while(*str!='\0')
    {
        if(*str>=65 && *str<=97)
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


    iRet=CountCapital(Arr);

    cout<<"Count is"<<iRet;

    return 0;
}