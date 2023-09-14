#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;


void Insert(PPNODE head,int no)
{
    printf("Heelo");
    PNODE temp=*head;
    PNODE newn= (PNODE)malloc(sizeof(NODE));

  

    newn->data=no;
    newn->next=NULL;

  
    if(*head==NULL)
    {
        printf("Heelo");
        *head=newn;
        return;
    }

    if(((*head)->data)<(no))
    {
         printf("Heelo");
        while((temp->next->data)<(no))
        {
            temp=temp->next;
           
        }

        newn->next=temp->next;
        temp->next=newn;
        return;
    }
    else
    {
        printf("Heelo");
        newn->next=(*head);
        *head=newn;
        return;
    }



    

}

void Display(PNODE head)
{
   
   printf("Elements are:\n");
   while(head!=NULL)
   {
       printf(" |%d|-> ",head->data);
       head=head->next;
   }
   printf("NULL\n");

}


int main()
{


    PNODE First=NULL;
    printf("Heelo");

    Insert(&First,10);
    Insert(&First,20);
    Insert(&First,5);
    Insert(&First,15);


    




    Display(First);




    return 0;

}