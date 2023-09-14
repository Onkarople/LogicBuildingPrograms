#include<stdio.h>
#include<stdlib.h>


//sturtie decleration
struct node
{ 
    int data;   //4
    struct node *next;  //8
    
};

    typedef struct node NODE;
    typedef struct node * PNODE;
    typedef struct node ** PPNODE;

    //juna nav       nawin nav
    // struct node    NODE
    // struct node *  PNODE
    //struct node ** PPNODE

int main()
{
    //static memeory allocation
     NODE obj;

//dynamic memeory allocation
   PNODE ptr=(PNODE)malloc(sizeof(NODE));
   
    obj.data=11;   //direct accesing operator
    obj.next=NULL;


    ptr->data=11;  // indirect accesing operator
    ptr->next=NULL;


    return 0;
}