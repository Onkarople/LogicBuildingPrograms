#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{
    char fname[20];
    int fd=0;         //File Descripter

    printf("Enter the name of file\n");
    scanf("%s",fname);

   fd=creat(fname,0777);    
   

   if(fd==-1)
   {
    printf("unable to create file\n");
    return -1;
   }

   printf("file is sucessfully created with fd %d\n",fd);


   return 0;

}