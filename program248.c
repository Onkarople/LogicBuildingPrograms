#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
//Maximum throughput in minimum hardware movement

#define FILESIZE 1024

int CountSmall(char Fname[])
{
    char data[FILESIZE];
    int iCnt=0;
    int iret=0;
    int iCnt1=0;
   
   int fd=0;
   fd=open(Fname,O_RDONLY);

   while((iret=read(fd,data,sizeof(data)))!=0)
   {

       for(iCnt=0;iCnt<iret;iCnt++)
      {
           
        if(data[iCnt]>='a' && data[iCnt]<='z')
        {
            iCnt1++;
        }
    
      }
    
   }

   return iCnt1;

   
}

int main()
{
   char Fname[20];
   char Data[10];
   int fd=0;
   int iRet=0;


   printf("Enter the Name of file to open\n");
   scanf("%s",Fname);

   iRet=CountSmall(Fname);

   printf("Number of small Letters are %d",iRet);
 
    return 0;
}