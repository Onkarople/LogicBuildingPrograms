#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


//o_RDONLY  read
//O_WRONLY  write
//O_RDWR    Read+write
int main()
{
    char fname[20];
    char Data[100];
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

   printf("Enter the data that you want to write:\n");
   scanf(" %[^'\n']s",Data);


   iRet=write(fd,Data,strlen(Data));
   printf("%d bytes gets sucessfully written in file\n",iRet);




   return 0;

}