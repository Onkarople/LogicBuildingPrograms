#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
//Maximum throughput in minimum hardware movement

#define FILESIZE 1024

int CountWhite(char Fname[])
{
    char data[FILESIZE];
    int iCnt=0;
    int iret=0;
    int iCount=0;
   
   int fd=0;
   fd=open(Fname,O_RDONLY);

   while((iret=read(fd,data,sizeof(data)))!=0)
   {

       for(iCnt=0;iCnt<iret;iCnt++)
      {
           
        if(data[iCnt] ==' ')
        {
            iCount++;
        }
    
      }
    
   }

   return iCount;

   
}

int main()
{
   char Fname[20];
   char Data[10];
   int fd=0;
   int iRet=0;


   printf("Enter the Name of file to open\n");
   scanf("%s",Fname);

   iRet=CountWhite(Fname);

   printf("Number of Spaces are %d",iRet);
 
    return 0;
}