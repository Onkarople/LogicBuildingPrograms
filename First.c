#include<stdio.h>

struct Demo
{
   int i;
   int j;
   struct demo *ptr;

};

union hello
{
  int g;
  int h;
  double d;

};

int main()
{
    int no=11;
    char ch='M';
    float f=3.14;
    double dValue=20.00;

    int k;

    int Arr[5];

    Arr[0]=10;
    Arr[1]=11;

    int Brr[5]={10,20,30,40};

    int *pBrr = NULL;
    pBrr=&(Brr[0]);

    int Crr[2][3];


    int *ptr=NULL;
    ptr=&no;

    struct Demo obj;

    obj.i=10;

    struct Demo *p=NULL;
    p=&obj;

    p->j=20;

    printf("jay ganesh \n");
    scanf("%d",&k);


    void *q=NULL;

    q= (int *) malloc(5*sizeof(int));

    union hello obj1;

    obj1.d=20.21;

    if(no>k)
    {
      printf("hello\n");
    }
    
    char Krr[5]="helo";

    char Frr[5]={'a','b','c','d','\0'};

    return 0;
}