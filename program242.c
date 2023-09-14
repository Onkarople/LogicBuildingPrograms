#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char fname[20];
    char Data[10];  //Mug
    int fd=0;      
    int iRet=0;   //File Descripter

    printf("Enter the name of file to open\n");
    scanf("%s",fname);
   

   fd=open(fname,O_RDWR | O_APPEND);
   if(fd==-1)
   {
    printf("unable to open file\n");
    return -1;
   }

   printf("file is sucessfully opened with fd %d\n",fd);


    read(fd,Data,sizeof(Data));
    read(fd,Data,sizeof(Data));
    read(fd,Data,sizeof(Data));
    read(fd,Data,sizeof(Data));
       



   return 0;

   //0  STDIN   KEYBOARD
   //1  STDOUT  Monitor
   //2  STDERR  Monitor

}