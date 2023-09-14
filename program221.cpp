#include<iostream>

using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class SinglyLL
{
   public:
      struct node<T> *Head;
      int Count;


      SinglyLL()
      {
        Head=NULL;
        Count=0;
      }
};


int main()
{
  SinglyLL <int>obj1; 

  SinglyLL <float>obj2; 

    return 0;
}