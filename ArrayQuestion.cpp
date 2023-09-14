#include<iostream>
using namespace std;


int main()
{
    int A=0;
    int i=0,j=0;
    int B=1;
    cout<<"Enter number\n";
    cin>>A;

    int Arr[A][A];
    cout<<"Enter elements od array\n";

    for( i=0;i<A;i++)
    {
        for(j=0;j<A;j++)
        {
            cin>>Arr[i][j];
        }
    }

  
          if(A>2)
            {
               cout<<A*(A-1);
            }
            else
            {
                cout<<B;
            }
    



    return 0;


}