#include<iostream>
using namespace std;

void strrevX(char *str)
{
  char *start = str;
  char *end =str;
 char  temp;

  while(*end!='\0')
  {
      end++;
  }  
   
   end--;

   while(start<end)
   {
       temp=*start;
       *start=*end;
       *end=temp;

        start++;
        end--;
   }

}

int main()
{
    char Arr[20];

    cout<<"Enter String\n";
    cin.getline(Arr,20);


     strrevX(Arr);

    cout<<"String after reverse is :"<<Arr<<endl;

    return 0;
}