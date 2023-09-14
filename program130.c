#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;          //*

};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void Display(PNODE head)
{
    printf("data from linked list is:\n");
    while(head!=NULL)
    {
        printf("|%d|<=>",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
     int iCnt=0;
     while(head!=NULL)
    {
        iCnt++;
        head=head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE head,int no)
{
   PNODE newn=NULL;

   newn=(PNODE)malloc(sizeof(NODE));
  
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;           //*


   if(*head==NULL)       //if LL is empty
   {
       *head=newn;
   }
   else                 //' if LL contains at leat one node
   {
        newn->next=*head;
        (*head)->prev=newn;    //* newn->next->prev=Newn;
        *head=newn;
   }

}

void InsertLast(PPNODE head,int no)
{
  PNODE newn=NULL;
  PNODE temp=NULL;

   newn=(PNODE)malloc(sizeof(NODE));
  
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;           //*


   if(*head==NULL)       //if LL is empty
   {
       *head=newn;
   }
   else                 //' if LL contains at leat one node
   {
        temp=*head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }

         temp->next=newn;
         newn->prev=temp;   //*  temp->next->prev=temp;
   }
  
}

void DeleteFirst(PPNODE head)
{
    

}

void DeleteLast(PPNODE head)
{}

void InsertAtPos(PPNODE head,int no,int pos)
{

}

void DeleteAtPos(PPNODE head,int pos)
{
    
}



int main()
{
  int iRet=0;
  PNODE First=NULL;

  InsertFirst(&First,21);
  InsertFirst(&First,11);

  InsertLast(&First,51);
  InsertLast(&First,101);

  Display(First);

  iRet=Count(First);

   printf("Number of nodes are:%d\n",iRet);

    return 0;
}