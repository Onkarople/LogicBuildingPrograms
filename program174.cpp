#include<iostream>
using namespace std;

int CountL(char *str)
{
   int iCnt=0;
   while(*str!='\0')
   {
       if(*str=='l')
       {
           iCnt++;
       }
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
  
   iRet=CountL(Arr);
   cout<<"String conatins "<<iRet<<" times"<<"\n";
 
  return 0;
}