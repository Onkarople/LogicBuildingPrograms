#include<iostream>

using namespace std;

int main()
{
    int a=0,iSum=0;
    int Ans=0;
    int B=0;
    int i=0;
    cout<<"Enter number\n";
    cin>>a;
    int Arr[a];
    for(i=0;i<a;i++)
    {
        cin>>Arr[i];
    }

    cout<<"Enter Integer\n";
    cin>>B;

    if(B==1)
    {
     for(i=0;i<a;i++)
       {
         iSum=iSum+Arr[i];
       }

  
    iSum=iSum*iSum;

    cout<<"Sum is";

    cout<<iSum<<endl;
   }
   else if(B>1)
   {
       for(i=0,iSum=0;i<a-(B-1);i++)
       {
         iSum=iSum+Arr[i];
       }

       Ans=Arr[a-(B-1)]*Arr[a-1];

       iSum=iSum*iSum;

       iSum=iSum+Ans;

       cout<<iSum<<endl;

   }



return 0;



}
