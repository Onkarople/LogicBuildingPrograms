#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//Read=4,Write=2,Exute=1
//permissions 0_owner_Group_Other;
int main()
{
    char fname[20];
    char Data[100];
    int fd=0;         //File Descripter

    printf("Enter the name of file\n");
    scanf("%s",fname);

    printf("enter the data\n");
    scanf(" %[^'\n']s",Data);


   fd=creat(fname,0777);    
   

   if(fd==-1)
   {
    printf("unable to create file\n");
    return -1;
   }

   printf("file is sucessfully created with fd %d\n",fd);
 
  write(fd,Data,strlen(Data));

   return 0;

}