#include<stdio.h>
#include<stdlib.h>


struct node
{
   int data;
   struct node * next;
};


typedef struct node  NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void InsertFirst(PPNODE head,int no)
{ 
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;


    if(*head==NULL)
    {
        *head=newn;
    }
    else
    {
        newn->next=*head;
        *head=newn;
    }

}
void InertLast(PPNODE head,int no)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;


    if(*head==NULL)
    {
        *head=newn;
    }
    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
}


void Display(PNODE head)
{
   printf("Elements are\n");
   while (head!=NULL)
   {
       printf("|%d|->",head->data);
       head=head->next;
   }
   printf("NULL\n");

}



int Count(PNODE head)
{
    int iCnt=0;
    while (head!=NULL)
    {
        iCnt++;
       head = head->next;
    }
    
    return iCnt;
}

void DeleteFirst(PPNODE head)
{
    PNODE temp=NULL;

    if(*head==NULL)
    {
        return;
    }

    if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        temp=*head;
        *head=temp->next;
        free(temp);
    }


}
void DeleteLast(PPNODE head)
{

PNODE temp=NULL;

    if(*head==NULL)
    {
        return;
    }

    if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        temp=*head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
   
        free(temp->next);
        temp->next=NULL;

    }


}

void InsertAtPos(PPNODE head,int no,int pos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
   int iCnt=0,size=0;
   size=Count(*head);

    if(pos<1||pos>size+1)
    {
        return;
    }


    if(pos==1)
    {
        InsertFirst(head,no);
    }
    else if(pos==size+1)
    {
        InertLast(head,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;


        temp=*head;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;

    }

}
void DeleteAtPos(PPNODE head,int pos)
{

    PNODE temp=NULL;
    PNODE tempdelete=NULL;
   int iCnt=0,size=0;
   size=Count(*head);

    if(pos<1||pos>size)
    {
        return;
    }


    if(pos==1)
    {
        DeleteFirst(head);
    }
    else if(pos==size)
    {
        DeleteLast(head);
    }
    else
    {
        temp=*head;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }

        tempdelete=temp->next;
        temp->next=temp->next->next;
        free(tempdelete);


    }



}


int main()
{
   int iRet=0;
   PNODE First=NULL;

   InsertFirst(&First,21);
   InsertFirst(&First,11);

   InertLast(&First,51);
   InertLast(&First,101);

   Display(First);

   iRet=Count(First);
   printf("Count is:%d\n",iRet);

   DeleteFirst(&First);
   DeleteLast(&First);

   Display(First);

   iRet=Count(First);
   printf("Count is:%d\n",iRet);


   InsertAtPos(&First,75,2);
    Display(First);

    iRet=Count(First);
   printf("Count is:%d\n",iRet);

   DeleteAtPos(&First,2);

   Display(First);

   iRet=Count(First);
   printf("Count is:%d\n",iRet);





   return 0;
}