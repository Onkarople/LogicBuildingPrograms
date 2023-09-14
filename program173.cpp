#include<iostream>
using namespace std;

int StrlenX(char *str)
{
   int iCnt=0;
   while(*str!='\0')
   {
       iCnt++;
       str++;
   }
   return iCnt;
}

int main()
{
  int iRet=0;
  char Arr[20];
  cout<<"enter string"<<endl;
  cin.getline(Arr,20);
  
   iRet=StrlenX(Arr);
   cout<<"Count is:"<<iRet<<"\n";
 
  return 0;
}