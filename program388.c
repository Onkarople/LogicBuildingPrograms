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


int main()
{
    PNODE First = NULL;
    int iret=0;
    int no=0;

    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,20);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    printf("Enter number\n");
    scanf("%d",&no);



    iret=Frequency(First,no);

    printf("frequency is :%d",iret);

    return 0;
}
