/* 

    read whole file 

    accept file name and print full content on console 
    use a buffer loop (read () until 0 )
    show total bytes read 

*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>

int main ()
{
    char fName [256] ;
    char Buffer [4096] ;    
    char mode [20] ;
    int fd = 0  , iBytes = 0 , iRet = 0  ; 

    struct stat obj  ; 
        
    printf(" enter file name to open the file \n ") ;
    scanf("%s",fName) ;

    
    fd = open ( fName ,  O_RDONLY ) ;

    if (fd == -1 )
    {
        perror(" \n" ) ;
        return -1 ;
    }
    else 
    {
        printf(" file opeened sucessfuly with fd : %d \n ",fd ) ;
    }


     iRet = stat ( fName , &obj ) ; 


 
   iRet = read ( fd , Buffer , obj.st_size ) ;
   
   
    printf(" the  total bytes read are : %d data from file is : %s \n ",iRet ,Buffer) ;

    close(fd) ;

   
    return 0 ; 
}