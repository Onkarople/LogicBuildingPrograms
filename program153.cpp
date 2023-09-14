#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;



class SinglyCLL
{
   private:             //charaterstics
     PNODE Head;
     PNODE Tail;

    public:              //beheviours
      SinglyCLL()
      {
          Head=NULL;
          Tail=NULL;
      }


};

int main()
{
  SinglyCLL obj;

    return 0;
}