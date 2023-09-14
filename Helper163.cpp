#include"Header163.h"

 DoublyCLL::DoublyCLL()
       {
           head=NULL;
           tail=NULL;
           CountNode=0;
       }

void DoublyCLL::InsertFirst(int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(CountNode==0) //if(head==NULL && tail==NULL)
    {
        head=newn;
        tail=newn;
        
    }
    else
    {
        newn->next=head;
        head->prev=newn;
        head=newn;
        
    }
        head->prev=tail;
        tail->next=head;
        CountNode++;

}
    
void DoublyCLL::InsertLast(int no)
{
  PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(CountNode==0) //if(head==NULL && tail==NULL)
    {
        head=newn;
        tail=newn;
        
    }
    else
    {
        tail->next=newn;
        newn->prev=tail;
        tail=newn;
    }
        head->prev=tail;
        tail->next=head;
        CountNode++;

}


void DoublyCLL::InsertAtPos(int no,int iPos)
{
    if(iPos<1 || iPos>CountNode+1)
    {
        cout<<"Invalid position\n";
        return;

    }

    if(iPos==1)
    {
        InsertFirst(no);
    }

    else if(iPos==CountNode+1)
    {
        InsertLast(no);
    } 
    else
    {
        PNODE newn=NULL;
        PNODE temp=head;
        int iCnt=0;
        newn=new NODE;

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

         CountNode++;
    }

   
}

void DoublyCLL::DeleteFirst()
{
    if(CountNode==0)
    {
        return;
    }

    if(CountNode==1)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=head->next;
        delete tail->next;  //delete head->prev;
        
    }
    head->prev=tail;
    tail->next=head;
    CountNode--;

}

void DoublyCLL::DeleteLast()
{
    if(CountNode==0)
    {
        return;
    }

    if(CountNode==1)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        tail=tail->prev;
        delete tail->next;
    }
    head->prev=tail;
    tail->next=head;
    CountNode--;
}

void DoublyCLL::DeleteAtPos(int iPos)
{
    if(iPos<1 || iPos>CountNode)
    {
        cout<<"Invalid position\n";
        return;

    }

    if(iPos==1)
    {
        DeleteFirst();
    }

    else if(iPos==CountNode)
    {
       DeleteLast();
    } 
    else
    {
        PNODE temp=head;
        int iCnt=0;

        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
         
         temp->next=temp->next->next;
         delete temp->next->prev;
         temp->next->prev=temp;
         CountNode--;

    }
}

void DoublyCLL::Display()
{
    PNODE temp=head;
    int iCnt=0;

    for(iCnt=1;iCnt<=CountNode;iCnt++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"\n";
}

int DoublyCLL::Count()
{
    return CountNode;
}