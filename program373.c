#include<stdio.h>

 void BubbleSort(int arr[],int n)
 {
   int i,j,temp;

  for(i=0;i<n;i++)
  {
     for(j=0;j<n-i-1;j++)
     {
        if(arr[j]>arr[j+1])
        {
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
        }

    }
  }
  printf("Elemnts are");
   for(i=0;i<6;i++)
   {
      scanf("%d",arr[i]);
   }

}

int main()
{
   int Arr[6];
   int i=0;

   printf("Enter values");
   for(i=0;i<6;i++)
   {
      scanf("%d",Arr[i]);
   }

   BubbleSort(Arr,6);


   return 0;
}
