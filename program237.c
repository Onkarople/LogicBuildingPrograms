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
    int fd=0;         //File Descripter

    printf("Enter the name of file to open\n");
    scanf("%s",fname);
   

   fd=open(fname,O_RDONLY);
   if(fd==-1)
   {
    printf("unable to open file\n");
    return -1;
   }

   printf("file is sucessfully opened with fd %d\n",fd);
 

   return 0;

}