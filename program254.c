#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>


int main()
{
    char Fname[20];
    char Data[10];
    int fd=0;
   
    printf("Enter the name of file\n");
    scanf("%s",Fname);

    fd=open(Fname,O_RDONLY);
    if(fd==-1)
    {
        printf("Unable yo open file\n");
        return -1;
    }

    lseek(fd,10,0);  
    
    //0=start
    //1=current
    //2=end

    read(fd,Data,5);

    write(1,Data,5);
                     
    

    return 0;
}

