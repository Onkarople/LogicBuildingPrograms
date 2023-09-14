#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*Head != NULL)
    {
        newn->next = *Head;
    }
    *Head = newn;
}

void Display(PNODE Head)
{
    printf("Elements of linked list are : \n");
    while(Head != NULL)
    {
        printf("|%d|-> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

int Summation(PNODE head)
{
    int iSum=0;
    while(head!=NULL)
    {
        iSum=iSum+(head->data);
        head=head->next;
    }
    return iSum;
}

int SearchMax(PNODE head)
{
   
    int iMax=0;

    if(head!=NULL)
    {
      iMax=head->data;
    }
   

    while(head!=NULL)
    {
        if((head->data)>iMax)
        {
            iMax=(head->data);
            
        }
        head=head->next;

    }
    return iMax;

}

int Frequency(PNODE head,int no)
{
    int iCnt=0;


    while(head!=NULL)
    {
        if((head->data)==no)
        {
            iCnt++;
            
        }
        head=head->next;

    }
    return iCnt;

}

void perfect(PNODE head)
{
    int iNo=0;
    int iSum=0;
    int i=0;
    while(head!=NULL)
    {
       
        for(i=1,iSum=0,iNo=head->data;i<iNo/2;i++)
        {
            if(iNo%i==0)
            {
                iSum=iSum+i;
            }
        }
            if(iSum==iNo)
            {
             
              printf("perfect number is %d\n",iNo);
            
            }
            head=head->next;
            

        }
    }



void SumDigit(PNODE head)
{
    int iNo=0;
    int isum=0;

    while(head!=NULL)
    {
        iNo=head->data;

        while(iNo!=0)
        {
            isum=isum+(iNo%10);
            iNo=iNo/10;
        }

        printf("sum is %d\n",isum);
        isum=0;
        head=head->next;
    }
}

int FirstOccurance(PNODE head,int no)
{

    int iPos=0;

    while(head!=NULL)
    {
        iPos++;
        if(head->data==no)
        {
            break;
        }
        head=head->next;
    }

   if(head==NULL)
   {
     return -1;
     
   }
   else
   {
     return iPos;
   }


}

int LastOccurance(PNODE head,int no)
{

    int iPos=0;
    int iPos2=-1;

    while(head!=NULL)
    {
        iPos++;
        if(head->data==no)
        {
           iPos2=iPos;
        }
        head=head->next;
    }

    return iPos2;

}



int main()
{
    PNODE First = NULL;
    int iret=0;
    int no=0;

    InsertFirst(&First,6);
    InsertFirst(&First,28);
    InsertFirst(&First,496);
    InsertFirst(&First,128);
    InsertFirst(&First,6);

    Display(First);

    iret=LastOccurance(First,10);

    if(iret==-1)
    {
        printf("there is no such element");
    }
    else
    {
        printf("occuramce is %d",iret);
        
    }


    return 0;
}
