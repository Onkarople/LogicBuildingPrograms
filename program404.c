#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE,**PPNODE;


void Insert(PPNODE head,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    PNODE temp=*head;

    newn->data=iNo;
    newn->lchild=NULL;
    newn->rchild=NULL;


    if(*head==NULL)  //if bst is empty
    {
        *head=newn;
    }
    else
    {

        while(1)
        {
            if(iNo>temp->data) //r
            {
               if(temp->rchild==NULL)
               {
                 temp->rchild=newn;
                 break;
               }
               temp=temp->rchild;
            }
            else if(iNo<temp->data) //l
            {
                if(temp->lchild==NULL)
               {
                 temp->lchild=newn;
                 break;
               }
               temp=temp->lchild;
            }
            else if(iNo==temp->data)
            {
                free(newn);
                printf("Data is alray there in bst");
                break;
            }
        }

    }

}

void Inorder(PNODE head)
{
    if(head!=NULL)
    {
        Inorder(head->lchild);
        printf("%d ",head->data);
        Inorder(head->rchild);
    }
}

void Preorder(PNODE head)
{
    if(head!=NULL)
    {
        printf("%d ",head->data);
        Preorder(head->lchild);
        Preorder(head->rchild);
    }
}

void Postorder(PNODE head)
{
    if(head!=NULL)
    {
        
        Postorder(head->lchild);
        Postorder(head->rchild);
        printf("%d ",head->data);
    }
}

bool search(PNODE head,int iNo)
{
   
   
    while(head!=NULL)
    {
        if(head->data==iNo)
        {
            break;
        }
        else if(iNo>head->data)
        {
            head=head->rchild;
        }
        else if(iNo<head->data)
        {
            head=head->lchild;
        }
    }
   if(head==NULL)
   {
     return false;
   }
   else
   {
    return true;
   }
}

int main()
{
    PNODE First=NULL;
    bool bRet=false;

    Insert(&First,11);
    Insert(&First,21);
    Insert(&First,7);

    //7 11 21    L D R      //inorder
    //11 7 21    D L R      //preorder
    //7 21 11    L R D      //postorder

    printf("\nInorder data:\n");
    Inorder(First);

    printf("\nPostorder data:\n");
    Postorder(First);

    printf("\nPreorder data:\n");
    Preorder(First);

    bRet=search(First,10);
    if(bRet==true)
    {
        printf("\nelement is there\n");
    }
    else
    {
        printf("\nNot there\n");
    }


    return 0;
}