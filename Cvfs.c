#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>  //for macro
//#include<io.h>


#define MAXINODE 50

#define READ 1
#define WRITE 2

#define MAXFILESIZE 1024 //limations 

#define REGULAR 1
#define SPECIAL 2


#define START 0
#define CURRENT 1
#define END 2

typedef struct superblock
{
    int TotalInodes;
    int FreeInode;

}SUPERBLOCK,*PSUPERBLOCK;


typedef struct inode
{
    char Filename[50];
    int InodeNumber;
    int Filesize;
    int FileAcualSize;
    int FileType;
    char *Buffer;
    int LinkCount;
    int ReferenceCount;
    int permission;   // 1 2 3
    struct inode *next;
}INODE,*PINODE,**PPINODE;


typedef struct filetable
{
    int readoffset;
    int writeoffset;
    int count;
    int mode; // 1 2 3
    PINODE ptrinode;    //pointing to inode
}FILETABLE,*PFILETABLE;


typedef struct ufdt   
{
    PFILETABLE ptrfiletable; //filetable //pointer ahe file table sathi
}UFDT;


UFDT UFDTArr[MAXINODE];   //ufd memeber arry // structure cha object tayar kela// ufdt area
SUPERBLOCK SUPERBLOCKobj;
PINODE head=NULL;

/////////////////////////////////////////////////////////////////
//Name of function:man
//Input Parameters:character pointer
//Return Value:NULL
//Description:Gives description and usages about commands
/////////////////////////////////////////////////////////////////


void man(char *name)
{
    if(name==NULL)return;

    if(strcmp(name,"create")==0)
    {
        printf("description:Used to create new regular file\n");
        printf("Usage:read create File_name Permission\n");
    }
    else if(strcmp(name,"read")==0)
    {
        printf("description:Used to read data from regular file\n");
        printf("Usage:read read File_name No_Of_Bytes_To_Read\n");
    }
    else if(strcmp(name,"write")==0)
    {
        printf("description:Used to write into regular file\n");
        printf("Usage:read write File_name\n After this enter data taht we want to write\n");
    }
     else if(strcmp(name,"ls")==0)
    {
        printf("description:Used to list all information of file\n");
        printf("Usage: ls\n");
    }
    else if(strcmp(name,"stat")==0)
    {
        printf("description:Used to display information of file\n");
        printf("Usage:stat File_name\n");
    }
   else if(strcmp(name,"fstat")==0)
    {
        printf("description:Used to display information of file\n");
        printf("Usage: fstat File_Descripter\n");
    }
    else if(strcmp(name,"truncate")==0)
    {
        printf("description:Used remove data from file\n");
        printf("Usage: truncate File_name\n");
    }
    else if(strcmp(name,"open")==0)
    {
        printf("description:Used to open existing file\n");
        printf("Usage: open File_name mode\n");
    }
    else if(strcmp(name,"close")==0)
    {
        printf("description:Used to close opened file\n");
        printf("Usage: close File_name\n");
    }
    else if(strcmp(name,"closeall")==0)
    {
        printf("description:Used to close all opened  files\n");
        printf("Usage: closeall\n");
    }
    else if(strcmp(name,"lseek")==0)
    {
        printf("description:Used to change  file offset\n");
        printf("Usage: lseek File_name ChangeInOffset StartPoint\n");
    }
    else if(strcmp(name,"rm")==0)
    {
        printf("description:Used to delete the file\n");
        printf("Usage: rm File_name\n");
    }
    else
    {
        printf("ERROR: No manual entery available\n");
    }

}

/////////////////////////////////////////////////////////////////
//Name of function:DisplyHelp
//Input Parameters:NULL
//Return Value:NULL
//Description:Display all commands with its useges
/////////////////////////////////////////////////////////////////


void DisplayHelp()
{
    printf("ls: To list Out all files\n");
    printf("clear: To clear console\n");
    printf("open: To open a file\n");
    printf("close: To close the file\n");
    printf("closeall: To close  all opened files\n");
    printf("read: To read the contents from file\n");
    printf("write: To write conetents into file\n");
    printf("exit: To terminate file System\n");
    printf("stat: To display information of file using name\n");
    printf("fstat: To dispaly information of file using file descripter\n");
    printf("truncate: To Remove All data from file\n");
    printf("rm: To delete the file\n");
    printf("create: To create new file\n");

}

/////////////////////////////////////////////////////////////////
//Name of function:GetFDFromName
//Input Parameters:character pointer
//Return Value:integer
//Description:gives the File Descripter from name of file.
/////////////////////////////////////////////////////////////////


int GetFDFromName(char *name)
{
    int i=0;

    while(i<MAXINODE)
    {
        if((UFDTArr[i].ptrfiletable!=NULL)&&(UFDTArr[i].ptrfiletable->ptrinode->FileType!=0))
        if(strcmp((UFDTArr[i].ptrfiletable->ptrinode->Filename),name)==0)
        break;
    
      i++;

    }

    if(i==MAXINODE)  return -1;
    else       return i;
}


/////////////////////////////////////////////////////////////////
//Name of function:Get_Inode
//Input Parameters:character pointer
//Return Value:pointer 
//Description:Gives Inode 
/////////////////////////////////////////////////////////////////


PINODE Get_Inode(char *name)
{
    PINODE temp=head;
    int i=0;

    if(name==NULL)
    return NULL;

    while (temp!=NULL)
    {
        if(strcmp(name,temp->Filename)==0)
        break;
        temp=temp->next;
    }
    
    return temp;
}

/////////////////////////////////////////////////////////////////
//Name of function:CreateDILB
//Input Parameters:NULL
//Return Value:NULL
//Description:create the Disk inode link block
/////////////////////////////////////////////////////////////////


void CreateDILB()    //link list tayr karne
{
    int i=1;
    PINODE newn=NULL;
    PINODE temp=head;

    while (i<=MAXINODE)
    {
        newn=(PINODE)malloc(sizeof(INODE));   //structure yevdhi szie allocation

        newn->LinkCount=0;
        newn->ReferenceCount=0;
        newn->FileType=0;
        newn->Filesize=0;

        newn->Buffer=NULL;
        newn->next=NULL;

        newn->InodeNumber=i;

        if(temp==NULL)
        {
            head=newn;
            temp=head;
        }
        else
        {
            temp->next=newn;
            temp=temp->next;
        }
        i++;
    }
    printf("DILB created successfully\n");
    
}

/////////////////////////////////////////////////////////////////
//Name of function:InitialiseSuperBlock
//Input Parameters:NULL
//Return Value:NULL
//Description:create superblock, which holds information of hard disk
/////////////////////////////////////////////////////////////////


void InitialiseSuperBlock()
{
    int i=0;
    while(i<MAXINODE)
    {
        UFDTArr[i].ptrfiletable=NULL;
        i++;
    }

    SUPERBLOCKobj.TotalInodes=MAXINODE;
    SUPERBLOCKobj.FreeInode=MAXINODE;
}

/////////////////////////////////////////////////////////////////
//Name of function:CreateFile
//Input Parameters:character pointer,interger
//Return Value:integer
//Description:to create a new file
/////////////////////////////////////////////////////////////////


int CreateFile(char *name,int permission)
{
    int i=0;
    PINODE temp=head;

    if(name==NULL || permission==0 || permission>3)
    return -1;

    if(SUPERBLOCKobj.FreeInode==0)
    return -2;

    (SUPERBLOCKobj.FreeInode)--;

    if(Get_Inode(name)!=NULL)
       return -3;


   while(temp!=NULL)
   {
     if(temp->FileType==0)
     break;
     temp=temp->next;
   }

   while (i<MAXINODE)
   {
      if(UFDTArr[i].ptrfiletable==NULL)
      break;
      i++;
   }

   UFDTArr[i].ptrfiletable=(PFILETABLE)malloc(sizeof(FILETABLE));

    UFDTArr[i].ptrfiletable->count=1;
    UFDTArr[i].ptrfiletable->mode=permission;
    UFDTArr[i].ptrfiletable->readoffset=0;
    UFDTArr[i].ptrfiletable->writeoffset=0;

    UFDTArr[i].ptrfiletable->ptrinode=temp;

    strcpy( UFDTArr[i].ptrfiletable->ptrinode->Filename,name);
    UFDTArr[i].ptrfiletable->ptrinode->FileType=REGULAR;
    UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount=1;
    UFDTArr[i].ptrfiletable->ptrinode->LinkCount=1;
    UFDTArr[i].ptrfiletable->ptrinode->Filesize=MAXFILESIZE;
    UFDTArr[i].ptrfiletable->ptrinode->FileAcualSize=0;
    UFDTArr[i].ptrfiletable->ptrinode->permission=permission;
    UFDTArr[i].ptrfiletable->ptrinode->Buffer=(char *)malloc(MAXFILESIZE);

    
   return i;

}


/////////////////////////////////////////////////////////////////
//Name of function:rm_File
//Input Parameters:character pointer
//Return Value:integer
//Description:it removes the file
/////////////////////////////////////////////////////////////////


int rm_File(char *name)
{
    int fd=0;

    fd=GetFDFromName(name);

    if(fd==-1)
    {
     return -1;
    }

   (UFDTArr[fd].ptrfiletable->ptrinode->LinkCount)--;

   if(UFDTArr[fd].ptrfiletable->ptrinode->LinkCount==0)
   {
        UFDTArr[fd].ptrfiletable->ptrinode->FileType=0;
        // free(UFDTArr[fd].ptrfiletable->ptrinode->Buffer);
        free(UFDTArr[fd].ptrfiletable);
   }

    UFDTArr[fd].ptrfiletable=NULL;
    (SUPERBLOCKobj.FreeInode)++;

  return 0;
    
}

/////////////////////////////////////////////////////////////////
//Name of function:readFile
//Input Parameters:character pointer,two integer
//Return Value:Integer
//Description:Read file 
/////////////////////////////////////////////////////////////////


int ReadFile(int fd,char *arr,int isize)
{
    int read_size=0;

    if(UFDTArr[fd].ptrfiletable==NULL)  return -1;

    if(UFDTArr[fd].ptrfiletable->mode!=READ && UFDTArr[fd].ptrfiletable->mode!=READ+WRITE)
    return -2;

    if(UFDTArr[fd].ptrfiletable->ptrinode->permission!=READ &&UFDTArr[fd].ptrfiletable->ptrinode->permission!=READ+WRITE)
    return -2;

    if(UFDTArr[fd].ptrfiletable->readoffset==UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)
    return -3;

    if(UFDTArr[fd].ptrfiletable->ptrinode->FileType!=REGULAR)
    return -4;

    read_size=(UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)-(UFDTArr[fd].ptrfiletable->readoffset);

    if(read_size<isize)
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer)+(UFDTArr[fd].ptrfiletable->readoffset),read_size);
        UFDTArr[fd].ptrfiletable->readoffset=UFDTArr[fd].ptrfiletable->readoffset+read_size;
    }
    else
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer)+(UFDTArr[fd].ptrfiletable->readoffset),isize);
        UFDTArr[fd].ptrfiletable->readoffset=UFDTArr[fd].ptrfiletable->readoffset+isize;
        
    }

    return isize;
}

/////////////////////////////////////////////////////////////////
//Name of function:WriteFile
//Input Parameters:character pointer,two ineteger
//Return Value:ineteger
//Description:used to write contents in file
/////////////////////////////////////////////////////////////////


int WriteFile(int fd, char *arr,int isize)
{
     if(UFDTArr[fd].ptrfiletable->mode!=WRITE && UFDTArr[fd].ptrfiletable->mode!=READ+WRITE)
    return -1;

    if(UFDTArr[fd].ptrfiletable->ptrinode->permission!=WRITE &&UFDTArr[fd].ptrfiletable->ptrinode->permission!=READ+WRITE)
    return -1;

    if((UFDTArr[fd].ptrfiletable->writeoffset)==MAXFILESIZE) return -2;

    if((UFDTArr[fd].ptrfiletable->ptrinode->FileType)!=REGULAR) return -3;

    strncpy((UFDTArr[fd].ptrfiletable->ptrinode->Buffer)+(UFDTArr[fd].ptrfiletable->writeoffset),arr,isize);

    UFDTArr[fd].ptrfiletable->writeoffset=UFDTArr[fd].ptrfiletable->writeoffset+isize;

    UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize=UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize+isize;


  return isize;              
}

/////////////////////////////////////////////////////////////////
//Name of function:OpenFile
//Input Parameters:character pointer,integer
//Return Value:ineteger
//Description:to open the existing file
/////////////////////////////////////////////////////////////////


int OpenFile(char *name,int mode)
{
    int i=0;
    PINODE temp=NULL;

    if(name==NULL || mode<=0)
    return -1;

    temp=Get_Inode(name);
    if(temp==NULL)
      return -2;

    if(temp->permission < mode)
      return -3;

    while(i<MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable==NULL)
         break;
         i++;
    }

    UFDTArr[i].ptrfiletable=(PFILETABLE)malloc(sizeof(FILETABLE));
    if( UFDTArr[i].ptrfiletable==NULL)  return -1;
    UFDTArr[i].ptrfiletable->count=1;
    UFDTArr[i].ptrfiletable->mode=mode;
       
    if(mode==READ+WRITE)
    {
        UFDTArr[i].ptrfiletable->readoffset=0;
        UFDTArr[i].ptrfiletable->writeoffset=0;
    }
    else if(mode==WRITE)
    {
        UFDTArr[i].ptrfiletable->writeoffset=0;
    }
    else if(mode==READ)
    {
        UFDTArr[i].ptrfiletable->readoffset=0;
    }

    UFDTArr[i].ptrfiletable->ptrinode=temp;
    (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)++;


     return i;


}

/////////////////////////////////////////////////////////////////
//Name of function:CloseFileByName
//Input Parameters:inetegr
//Return Value:NULL
//Description:close file by its fd
/////////////////////////////////////////////////////////////////


void CloseFileByfd(int fd)
{
    UFDTArr[fd].ptrfiletable->readoffset=0;
    UFDTArr[fd].ptrfiletable->writeoffset=0;
    (UFDTArr[fd].ptrfiletable->ptrinode->ReferenceCount)--;
}


/////////////////////////////////////////////////////////////////
//Name of function:CloseFileByName
//Input Parameters:character pointer
//Return Value:int
//Description:close file by its name.
/////////////////////////////////////////////////////////////////


int CloseFileByName(char *name)
{
   int i=0;
   i=GetFDFromName(name);

   if(i==-1)
   return -1;

    UFDTArr[i].ptrfiletable->readoffset=0;
    UFDTArr[i].ptrfiletable->writeoffset=0;
    (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)--;

    return 0;
}

/////////////////////////////////////////////////////////////////
//Name of function:CloseAllFile
//Input Parameters:NULL
//Return Value:NULL
//Description:close the all files.
/////////////////////////////////////////////////////////////////


void CloseAllFile()
{
    int i=0;
    while (i<MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable!=NULL)
        {
            UFDTArr[i].ptrfiletable->readoffset=0;
            UFDTArr[i].ptrfiletable->writeoffset=0;
            ( UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)--;
            break;
            
        }
        i++;
    }
    
}

/////////////////////////////////////////////////////////////////
//Name of function:LseekFile
//Input Parameters:three Integers
//Return Value:ineteger
//Description:Modify the file
/////////////////////////////////////////////////////////////////


int LseekFile(int fd,int size, int from)
{
    if(fd<0||from>2) return -1;
    if(UFDTArr[fd].ptrfiletable==NULL) return -1;

    if(UFDTArr[fd].ptrfiletable->mode==READ||UFDTArr[fd].ptrfiletable->mode==READ+WRITE)
    {
        if(from==CURRENT)
        {
            if((UFDTArr[fd].ptrfiletable->readoffset+size)>UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize) return -1;

            if(((UFDTArr[fd].ptrfiletable->readoffset)+size)<0) return -1;
            UFDTArr[fd].ptrfiletable->readoffset=UFDTArr[fd].ptrfiletable->readoffset+size;

        }

        else if(from==START)
        {
            if(size>(UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)) return -1;
            if(size<0) return -1;
            (UFDTArr[fd].ptrfiletable->readoffset)=size;
        }
        else if(from==END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)+size>MAXFILESIZE) return -1;
            if((UFDTArr[fd].ptrfiletable->readoffset)+ size<0) return -1;
            (UFDTArr[fd].ptrfiletable->readoffset)=(UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)+ size;
            
        }
    }

    else if(UFDTArr[fd].ptrfiletable->mode==WRITE)
    {
        if(from==CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->writeoffset) +size)>MAXFILESIZE) return -1;
            if(((UFDTArr[fd].ptrfiletable->writeoffset)+size)<0) return -1;
            if(((UFDTArr[fd].ptrfiletable->writeoffset)+size)>(UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)) 

            (UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)=(UFDTArr[fd].ptrfiletable->writeoffset)+size;

            (UFDTArr[fd].ptrfiletable->writeoffset)=(UFDTArr[fd].ptrfiletable->writeoffset)+size;

        }


        else if(from==START)
        {
            if(size>MAXFILESIZE)  return -1;
            if(size<0)  return -1;
            if(size>(UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize))
            (UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)=size;
            (UFDTArr[fd].ptrfiletable->writeoffset)==size;
        }

        else if(from==END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)+size>MAXFILESIZE)  return -1;

            if(((UFDTArr[fd].ptrfiletable->writeoffset)+size)<0) return -1;

            (UFDTArr[fd].ptrfiletable->writeoffset)=(UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize)+size;
        }


    }

    return 0;

}

/////////////////////////////////////////////////////////////////
//Name of function:ls_File
//Input Parameters:NULL
//Return Value:NULL
//Description:Display all files.
/////////////////////////////////////////////////////////////////


void ls_file()
{
    int i=0;
    PINODE temp=head;

    if(SUPERBLOCKobj.FreeInode==MAXINODE)
    {
        printf("ERROR:There are no files\n");
        return;
    }
  
   printf("\nFile Name\tInode Number\tFile size\tLink count\n");
   printf("..................................................................\n");
   while (temp!=NULL)
   {
       if(temp->FileType!=0)
       {
        printf("%s\t\t%d\t\t%d\t\t%d\n",temp->Filename,temp->InodeNumber,temp->FileAcualSize,temp->LinkCount);
       }
       temp=temp->next;
   }

   printf(".......................................................................\n");
   
}

/////////////////////////////////////////////////////////////////
//Name of function:fstat_file
//Input Parameters:Integer
//Return Value:Ineteger
//Description:Display information by using fd
/////////////////////////////////////////////////////////////////


int fstat_file(int fd)
{
    PINODE temp=head;
    int i=0;

    if(fd<0) return -1;

    if(UFDTArr[fd].ptrfiletable==NULL) return -2;

    temp=UFDTArr[fd].ptrfiletable->ptrinode;

    printf("\n...............Statistical Information about file..............\n");
    printf("File name:%s\n",temp->Filename);
    printf("Inode Number:%d\n",temp->InodeNumber);
    printf("File size:%d\n",temp->Filesize);
    printf("ActulFile size:%d\n",temp->FileAcualSize);
    printf("Link Count:%d\n",temp->LinkCount);
    printf("Reference Count:%d\n",temp->ReferenceCount);


    if(temp->permission==1)
    printf("File permission:read only\n");
    else if(temp->permission==2)
    printf("File permission:write only\n");
    else if(temp->permission==3)
    printf("File permission:read & write \n");
    printf("........................................\n\n");     


   return 0;

}

/////////////////////////////////////////////////////////////////
//Name of function:stat-file
//Input Parameters:character pointer
//Return Value:Inetegr
//Description:Display information by using its name
/////////////////////////////////////////////////////////////////


int stat_file(char *name)
{
    PINODE temp=head;
    int i=0;

    if(name==NULL) return -1;

    while(temp!=NULL)
    {
        if(strcmp(name,temp->Filename)==0)
        break;
        temp=temp->next;
    }

    if(temp==NULL) return -2;

    printf("\n...............Statistical Information about file..............\n");
    printf("File name:%s\n",temp->Filename);
    printf("Inode Number:%d\n",temp->InodeNumber);
    printf("File size:%d\n",temp->Filesize);
    printf("ActulFile size:%d\n",temp->FileAcualSize);
    printf("Link Count:%d\n",temp->LinkCount);
    printf("Reference Count:%d\n",temp->ReferenceCount);


    if(temp->permission==1)
    printf("File permission:read only\n");
    else if(temp->permission==2)
    printf("File permission:write only\n");
    else if(temp->permission==3)
    printf("File permission:read & write \n");
    printf("........................................\n\n");     


   return 0;

}

/////////////////////////////////////////////////////////////////
//Name of function:truncate_file
//Input Parameters:character pointer
//Return Value:Integer
//Description: removes data from file.
/////////////////////////////////////////////////////////////////


int truncate_File(char *name)
{
    int fd=GetFDFromName(name);
    if(fd==-1)
      return -1;

    memset( UFDTArr[fd].ptrfiletable->ptrinode->Buffer,0,1024);
    UFDTArr[fd].ptrfiletable->readoffset=0;
    UFDTArr[fd].ptrfiletable->writeoffset=0;
    UFDTArr[fd].ptrfiletable->ptrinode->FileAcualSize=0;

    return 0;
}

/////////////////////////////////////////////////////////////////
//Entry point Function for CVFS 
/////////////////////////////////////////////////////////////////


int main()
{
    char *ptr=NULL;
    int ret=0,fd=0,count=0;
    char command[4][80],str[80],arr[1024];

    InitialiseSuperBlock();
    CreateDILB();


    while(1)
    {
        fflush(stdin);
        strcpy(str,"");

        printf("\n Marvellous VFS:> ");

        fgets(str,80,stdin);

        count=sscanf(str,"%s %s %s %s",command[0],command[1],command[2],command[3]); //string madhe scan karun de

        if(count==1)
        {
            if(strcmp(command[0],"ls")==0)
            {
                ls_file();
            }
            else if(strcmp(command[0],"closeall")==0)
            {
                CloseAllFile();
                printf("All files closed succesfully\n");
                continue;
            }
            else if(strcmp(command[0],"clear")==0)
            {
                system("cls");
                continue;
            }
           else if(strcmp(command[0],"help")==0)
            {
                DisplayHelp();
                continue;
            }
            else if(strcmp(command[0],"exit")==0)
            {
                printf("Terminating the Marvellous Virtual File System\n");
                break;
            }
            else if (strcmp(command[0],"fd")==0)
            {
               
                int r=GetFDFromName(command[1]);
                printf("%d",r);
                continue;
            }
            
            else
            {
                 printf("\nERROE:Command not found!!!\n");
                 continue;
            }
            
        }

        else if(count==2)
        {
            if(strcmp(command[0],"stat")==0)
            {
                ret=stat_file(command[1]);
                if(ret==-1)
                  printf("ERROR: Incorrect parameters\n");
                if(ret==-2)
                  printf("ERROR:There is no such File\n");
                continue;
            }

            else if(strcmp(command[0],"fstat")==0)
            {
                ret=fstat_file(atoi(command[1]));
                if(ret==-1)
                  printf("ERROR: Incorrect parameters\n");
                if(ret==-2)
                  printf("ERROR:There is no such File\n");
                continue;
            }

            else if(strcmp(command[0],"close")==0)
            {
                ret=CloseFileByName(command[1]);

                if(ret==-1)
                  printf("ERROR:There is no such File\n");
                continue;
            }

             else if(strcmp(command[0],"rm")==0)
            {
                ret=rm_File(command[1]);
                if(ret==-1)
                  printf("ERROR:There is no such File\n");
                continue;
            }

             else if(strcmp(command[0],"man")==0)
            {
               man(command[1]);
            }

            else if(strcmp(command[0],"write")==0)
            {
                fd=GetFDFromName(command[1]);
                if(fd==-1)
                {
                    printf("ERROR:Incorrect parameter\n");
                    continue;
                }
                printf("Enter the data:\n");
                scanf("%[^\n]s",arr);

                ret=strlen(arr);
                if(ret==0)
                {
                    printf("ERROR:Incorrect Parameter\n");

                    continue;
                }

                ret=WriteFile(fd,arr,ret);
                if(ret==-1)
                  printf("ERROR:Permission denied\n");
                if(ret==-2)
                  printf("ERROR:There is no sufficient memeoery to write\n");
                if(ret==-3)
                   printf("ERROR: It is not regular file\n");
            }


            else if(strcmp(command[0],"truncate")==0)
            {
                ret=truncate_File(command[1]);
                if(ret==-1)
                printf("ERROR:Incorrect parameter\n");
            }
            else
            {
                printf("\nERROR:command not found!!!\n");
                continue;
            }

        }

        else if(count==3)
        {
            if(strcmp(command[0],"create")==0)
            {
                ret=CreateFile(command[1],atoi(command[2]));
                if(ret>=0)
                  printf("File is Succesfully created with file descripter:%d\n",ret);
                if(ret==-1)
                  printf("ERROR:Incorrect parameters\n");
                if(ret==-2)
                  printf("ERROR:There is No inodes\n");
                if(ret==-3)
                  printf("ERROR:File already exists\n");
                if(ret==-4)
                  printf("ERROR:Memeoery allocation failure\n");
                
                continue;

            }

            else if(strcmp(command[0],"open")==0)
            {
                ret=OpenFile(command[1],atoi(command[2]));
                if(ret>=0)
                  printf("File is Succesfully opened with file descripter:%d\n",ret);
                if(ret==-1)
                  printf("ERROR:Incorrect parameters\n");
                if(ret==-2)
                  printf("ERROR:File not present\n");
                if(ret==-3)
                  printf("ERROR:Permission denied\n");
                continue;
            }

            if(strcmp(command[0],"read")==0)
            {
                fd=GetFDFromName(command[1]);
                if(fd==-1)
                {
                    printf("ERROR:Incorrect parameters\n");
                    continue;
                }
                ptr=(char *)malloc(sizeof(atoi(command[2]))+1);

                if(ptr==NULL)
                {
                    printf("ERROR:Memeory allocation failure\n");
                    continue;
                }

                ret=ReadFile(fd,ptr,atoi(command[2]));
                if(ret==-1)
                  printf("ERROR:File not existing\n");
                if(ret==-2)
                  printf("ERROR:Permission Denied\n");
                if(ret==-3)
                  printf("ERROR:Reached at end of file\n");
                if(ret==-4)
                  printf("ERROR:it is not regular File\n");
                if(ret==0)
                   printf("ERROR:File empty\n");
                
                if(ret>0)
                {
                    write(2,ptr,ret);
                }
                continue;
            }

            else
            {
               printf("ERROR:Command not found!!!\n");
               continue;
            }

        }

        else if(count==4)
        {
            if(strcmp(command[0],"lseek")==0)
            {
                fd=GetFDFromName(command[1]);
                if(fd==-1)
                {
                   printf("ERROR:Incorrect parameter\n");
                   continue;
                }
                ret=LseekFile(fd,atoi(command[2]),atoi(command[3]));
                if(ret==-1)
                {
                    printf("ERROR:Unable to perform lseek\n");
                }
            }
            else
            {
                printf("\nERROR:Command not found!!!\n");
                continue;
            }
        }
        else
        {
            printf("\nERROR: Command not found!!!\n");
            continue;
        }
    }//end of while

    return 0;
}