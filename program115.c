#include<stdio.h>
#include<stdlib.h>
//sturtie decleration
struct node
{ 
    int data;   //4
    struct node *next;  //8
    
};

int main()
{
    //static memeory allocation
   struct node obj;

//dynamic memeory allocation
   struct  node *ptr=(struct node*)malloc(sizeof(struct node));
   
    obj.data=11;   //direct accesing operator
    obj.next=NULL;


    ptr->data=11;  // indirect accesing operator
    ptr->next=NULL;


    return 0;
}