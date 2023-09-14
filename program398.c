#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


void EvenDelete(PPNODE head)
{

   PNODE first=NULL;
   PNODE second=NULL;
   PNODE temp=NULL;

  if(*head==NULL) //if LL is empty
   {
     return;
   }

  if((*head)->next==NULL)
  {
    if((((*head)->data)%2)==0)
    {
     
       free(*head);
       *head=NULL;
       return;
     
    }
    else
    {
        return;
    }
  }

  first=*head;
  second=(*head)->next;

  while(second!=NULL)
  {
      
    if(second->data%2==0)
    {
      temp=second;
      first->next=second->next;
      free(temp);
      second=first->next;
    }
    else
    {
        first=second;
        second=first->next;
    }

  }

  if(((*head)->data)%2==0)
  {
    temp=*head;
    (*head)=(*head)->next;
    free(temp);
  }
  
      
}
   
   





int main()
{
    PNODE First = NULL;
    bool bret=false;
    int no=0;
    PNODE Third=NULL;
    PNODE Last=NULL;

    InsertFirst(&First,72);
    InsertFirst(&First,22);
    InsertFirst(&First,18);
    InsertFirst(&First,12);
    InsertFirst(&First,14);


    Display(First);

    EvenDelete(&First);

    Display(First);

    return 0;
}
