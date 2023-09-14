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
   

   fd=open(fname,O_RDWR);
   if(fd==-1)
   {
    printf("unable to open file\n");
    return -1;
   }

   printf("file is sucessfully opened with fd %d\n",fd);


    while((iRet=read(fd,Data,sizeof(Data)))!=0)
    {
        write(1,Data,iRet);
    }


    close(fd);



   return 0;

   //0  STDIN   KEYBOARD
   //1  STDOUT  Monitor
   //2  STDERR  Monitor

}