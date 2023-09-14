#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
   int data;
    node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;


class  Singly_Linkedlist
{
     public:
       PNODE head;
     
     public:
      Singly_Linkedlist();
      ~Singly_Linkedlist();
      BOOL InsertFirst(int);
      BOOL InsertLast(int);
      BOOL DeleteFirst();
      BOOL DeleteLast();
      BOOL InsertAtPos(int,int);
      BOOL DeleteAtPos(int);
      inline void Display();
      inline  int Count();

    
};

Singly_Linkedlist::Singly_Linkedlist()
{
    head=NULL;
}

Singly_Linkedlist::~Singly_Linkedlist()
{
      PNODE temp,Naviagte;
      if(head!=NULL)
      {
          Naviagte=head;
          while(Naviagte!=NULL)
          {
              temp=Naviagte->next;
              delete Naviagte;
              Naviagte=temp;
          }
      }
}

BOOL Singly_Linkedlist::InsertFirst(int no)
{
   PNODE newn=NULL;
   newn = new NODE;
   if(newn==NULL)
   {
       return FALSE;
   }

   newn->data=no;
   newn->next=NULL;

   if(head==NULL)
   {
       head=newn;
   }
   else
   {
       newn->next=head;
       head=newn;
   }
   return TRUE;
}

BOOL Singly_Linkedlist::InsertLast(int no)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
   newn = new NODE;
   if(newn==NULL)
   {
       return FALSE;
   }

   newn->data=no;
   newn->next=NULL;

   if(head==NULL)
   {
       newn=head;
   }
   else
   {
      temp=head;
      while(temp->next!=NULL)
      {
          temp=temp->next;
      }

      temp->next=newn;
   }
   return TRUE;
}

BOOL Singly_Linkedlist::DeleteFirst()

{
    PNODE temp=NULL;
    temp=head;
    if(head==NULL)
    {
        return FALSE;
    }

    else
    {
        head=head->next;
        delete(temp); 
    }
    return TRUE;
}

BOOL Singly_Linkedlist::DeleteLast()
{
    PNODE temp=NULL;
    PNODE temp2=NULL;
    temp=head;
    if(head==NULL)
    {
        return FALSE;
    }

    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=NULL;
        delete(temp2);
     
    }
    return TRUE;
}

BOOL Singly_Linkedlist::InsertAtPos(int no,int pos)
{
    PNODE temp=NULL;
    PNODE newn=NULL;
    int iCnt=0;

    if(head==NULL || pos>Count()+1||pos<0)
    {
        return FALSE;
    }

    if(pos==1)
    {
        return(InsertFirst(no));
    }
    else if(pos==Count()+1)
    {
        return(InsertLast(no));
    }

    else
    {
        temp=head;
        newn=new NODE;
        if(newn==NULL)
        {
            return FALSE;
        }

        newn->data=no;
        newn->next=NULL;

        for(iCnt=1;iCnt<=pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

    }
    return TRUE;
}

BOOL Singly_Linkedlist::DeleteAtPos(int pos)
{
    PNODE temp=NULL;
    PNODE temp2=NULL;
  
    int iCnt=0;

    if(head==NULL || pos>Count()||pos<0)
    {
        return FALSE;
    }

    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==Count())
    {
        DeleteLast();
    }

    else
    {
        temp=head;
        for(iCnt=1;iCnt<=pos-1;iCnt++)
        {
            temp=temp->next;
        }
       
         temp2=temp->next;
         temp->next=temp->next->next;
         delete(temp2);
    }
    return TRUE;
}

void Singly_Linkedlist::Display()
{
    PNODE temp=NULL;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";

}

int Singly_Linkedlist::Count()
{
    PNODE temp=NULL;
    temp=head;
    int iCnt=0;
    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}

int main()
{
   Singly_Linkedlist obj1;
   Singly_Linkedlist *obj2=new Singly_Linkedlist();


   obj1.InsertFirst(51);
   obj1.InsertFirst(21);
   obj1.InsertFirst(11);

   obj1.Display();

   cout<<"NODES are:"<<obj1.Count()<<"\n";

   obj1.InsertFirst(101);
   obj1.InsertFirst(111);

    obj1.Display();

   cout<<"NODES are:"<<obj1.Count()<<"\n";

   obj1.InsertAtPos(75,4);

   obj1.Display();

   cout<<"NODES are:"<<obj1.Count()<<"\n";

   obj1.DeleteFirst();
   obj1.Display();

   obj1.DeleteLast();
   obj1.Display();


   obj2->InsertFirst(501);
   obj2->InsertFirst(511);
   obj2->InsertFirst(521);

   obj2->Display();

   obj2->InsertLast(551);
   obj2->InsertAtPos(601,3);

    obj2->Display();

    cout<<"nodes are:"<<obj2->Count()<<"\n";

    delete obj2;

    return 0;
}