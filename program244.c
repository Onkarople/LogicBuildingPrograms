#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


void DisplayData(char fname[])
{
    char Data[10];
    int fd=0;
    int iRet=0;

   fd=open(fname,O_RDWR);
   if(fd==-1)
   {
    printf("unable to open file\n");
    return ;
   }

   printf("file is sucessfully opened with fd %d\n",fd);


    while((iRet=read(fd,Data,sizeof(Data)))!=0)
    {
        write(1,Data,iRet);
    }


    close(fd);
}


int main()
{
    char fname[20];    

    printf("Enter the name of file to open\n");
    scanf("%s",fname);
   
    DisplayData(fname);
    
    return 0;

   

}