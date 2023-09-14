#include<iostream>
using namespace std;

int main()
{
  char Arr[]="hello";
  int iCnt=0;

   while(Arr[iCnt]!='\0')
   {
      cout<<Arr[iCnt];
      iCnt++;
   }
 
    return 0;
}