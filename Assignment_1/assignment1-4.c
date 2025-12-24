/* 
    Display complete file information  
    Accept file name and display meta data of file using stat () 

*/


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>



int main ()
{
    char fName [256] ;  
    char mode [20] ;
    int fd = 0  , iRet = 0 ; 

   struct stat sobj ;
   
        
    printf(" enter file name to open the file \n ") ;
    scanf("%s",fName) ;

    
    fd = open ( fName ,  O_RDONLY ) ;

    if (fd == -1 )
    {
        perror(" \n" ) ;
    }
    else 
    {
        printf(" file opeened sucessfuly with fd : %d \n ",fd ) ;
    }
 
    iRet = stat( fName , &sobj ) ;

    if ( iRet == -1 )
    {
        perror(" \n ") ;
        return -1 ;
    }


    printf(" the inode no of file is : %lu \n ",sobj.st_ino) ;
    printf(" the no of hardlink is : %lu \n ",sobj.st_nlink) ;
    printf(" the size of file is  : %lu \n ",sobj.st_size) ;
    printf(" the group id is  : %lu \n ",sobj.st_gid) ;
    printf(" the block size is  : %lu \n ",sobj.st_blksize) ;
    printf(" the file type and mode of file is  : %lu \n ",sobj.st_mode) ;


     close(fd) ;

    return 0 ;
     
}