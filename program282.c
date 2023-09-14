#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;          
    struct node *next;    
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void InsertFirst(PPNODE Head,int No)
{
   PNODE newn=NULL;

   newn= (PNODE)malloc(sizeof(NODE)); 

   newn->data=No;
   newn->next=NULL;

   if(*Head==NULL)   
   {
     *Head = newn;
   }
   else          
   {
      newn->next=*Head;
      *Head=newn;
   }



}



void Display(PNODE head)
{

    if(head !=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
        Display(head);   //tail recursiion
    }
    
}



int Count(PNODE head)
{
   int iCnt=0;
    while(head !=NULL)
    {
        iCnt++;
        head=head->next;
    }

  return iCnt;
}


int main()
{
  int iRet=0;
  PNODE First=NULL;
 

  InsertFirst(&First,101);  
  InsertFirst(&First,51);
  InsertFirst(&First,21);
  InsertFirst(&First,11);


  Display(First);       

  iRet =Count(First);
  printf("Number of nodes are :%d\n",iRet);

  return 0;
}