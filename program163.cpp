#include"Header163.h"

int main()
{
     int iRet=0;
     DoublyCLL obj;

   obj.InsertFirst(51);
   obj.InsertFirst(21);
   obj.InsertFirst(11);

   obj.InsertLast(101);
   obj.InsertLast(111);

   obj.InsertLast(121);
   obj.InsertLast(151);



   obj.Display();

   iRet=obj.Count();

   cout<<"nodes are:"<<iRet<<endl;

   obj.InsertAtPos(75,4);

   obj.Display();

   iRet=obj.Count();

   cout<<"nodes are:"<<iRet<<endl;

   obj.DeleteAtPos(4);
   obj.Display();

   iRet=obj.Count();

   cout<<"nodes are:"<<iRet<<endl;


    return 0;
}