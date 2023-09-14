#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;          //4
    struct node *next;    //8
};
////////////////////////////////////////////

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
/////////////////////////////////////////////


void InsertFirst(PPNODE Head,int No)
{

    //allocate memeory for node(dynamically)
    //inistialise that node



    //check whwether ll is empty or not
    //if ll is empty then new node is the first node so upadte its address in first pointer through head


    //if ll is not empty then store the address of first node in the next pointer of our new node
    //update the first pointer through head

   PNODE newn=NULL;

   newn= (PNODE)malloc(sizeof(NODE)); //newn = (struct node*)malloc(12);

   newn->data=No;
   newn->next=NULL;

   if(*Head==NULL)   //LL is empty
   {
     *Head = newn;
   }
   else          //LL contains at leat one node
   {
      newn->next=*Head;
      *Head=newn;
   }



}
////////////////////////////////////


void InsertLast(PPNODE Head,int No)
{

    //allocate memeory for node(dynamically)
    //inistialise that node

    //check whwether ll is empty or not
    //if ll is empty then new node is the first node so upadte its address in first pointer through head

    //if ll is not empty then 
    //travel till last node of ll
    //store address of new node in the next pointer of last node

   PNODE newn=NULL;
   PNODE temp=NULL;

   newn= (PNODE)malloc(sizeof(NODE)); //newn = (struct node*)malloc(12);

   newn->data=No;
   newn->next=NULL;

   if(*Head==NULL)   //LL is empty
   {
     *Head = newn;
   }
   else          //LL contains at leat one node
   {
      temp=*Head;             //travel till last node
      while (temp->next!=NULL)  //store address of new 
      {
          temp=temp->next;
      }

      temp->next=newn;
                                   
   }

}

////////////////////////////////////////

void Display(PNODE head)
{
   printf("Elements from linked list are: \n");
   
    while(head !=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

/////////////////////////////////////
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
//////////////////////////////////


void DeleteFirst(PPNODE head)
{
   // if ll is empty tehn return
   // if ll contains at least one node then store the address of second node in the first pointer through head
   //and delete the first node

   PNODE temp=NULL;

 if(*head==NULL)         //ll is empty
 {
     return;
 }
 else                    ////LL contains atleast one node
 {
     temp=*head;
     *head=temp->next;
     free(temp);
 }

}


void DeleteLast(PPNODE head)
{
    //if LL is empty then return
    //if LL contains one node then delete that node and return
    //if LL contains more tahn one node then trave; till second last node and delete last node
    
    PNODE temp=NULL;


   if(*head==NULL) //if LL is empty
   {
       return;
   }
   else if((*head)->next==NULL)   //LL cpntains one node
   {
      free(*head);
      *head=NULL;
   }
   else               //if LL is contains more than one node
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
     //consider no of nodes are 4
     //if position is invalid then return directly(<1 or >5)
     //if position is 1 then call insertfirst
     //if position is n+1 then call insertlast(5)
     //
    int size=0;
    PNODE newn=NULL;
    PNODE temp=NULL;
    int iCnt=0;

    size=Count(*head);

     if((pos<1)||(pos>(size+1)))
     {
         printf("Position is inavlid");
         return;
     }


     if(pos==1)
     {
         InsertFirst(head,no);
     }
     else if(pos==(size+1))
     {
         InsertLast(head,no);

     }
     else     //logic
     {
        newn=NULL;

        newn= (PNODE)malloc(sizeof(NODE)); //newn = (struct node*)malloc(12);

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




int main()
{
  int iRet=0;
  PNODE First=NULL;
 

  InsertFirst(&First,101);  //call by address
  InsertFirst(&First,51);
  InsertFirst(&First,21);
  InsertFirst(&First,11);


  InsertAtPos(&First,75,3);


  Display(First);       //call by value

  iRet =Count(First);
  printf("Number of nodes are :%d\n",iRet);

  //////////////////////////////

  InsertFirst(&First,1);

  Display(First);       //call by value

  iRet =Count(First);
  printf("Number of nodes are :%d\n",iRet);

  InsertLast(&First,111);
  InsertLast(&First,121);

  Display(First);       //call by value

  iRet =Count(First);
  printf("Number of nodes are :%d\n",iRet);


  DeleteFirst(&First);
  DeleteFirst(&First);

  Display(First);       //call by value

  iRet =Count(First);
  printf("Number of nodes are :%d\n",iRet);


  DeleteLast(&First);

  Display(First);       //call by value

  iRet =Count(First);
  printf("Number of nodes are :%d\n",iRet);




  return 0;
}