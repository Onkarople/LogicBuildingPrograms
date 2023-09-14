#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define FILESIZE 1024

void FileCopy(char Scource[],char Destination[])
{
   char Buffer[FILESIZE];
   int Fdsrc=0;
   int Fddest=0;
   int iRet=0;

   Fdsrc=open(Scource,O_RDONLY);
   if(Fdsrc==-1)
   {
     printf("Unble to open Scource file\n");
      return ;
   }

   Fddest=creat(Destination,0777);
   if(Fddest==-1)
   {
     printf("Unable to create new file\n");
     return;
   }

   while((iRet=read(Fdsrc,Buffer,FILESIZE))!=0)
   {
      write(Fddest,Buffer,iRet);
   }

   close(Fdsrc);
   close(Fddest);





}

int main()
{
    char Fname1[20];
    char Fname2[20];

    printf("Enter the name of file which contains data\n");
    scanf("%s",Fname1);

    printf("Enter the name of file that you want to create\n");
    scanf("%s",Fname2);


    FileCopy(Fname1,Fname2);

    
    return 0;
}

