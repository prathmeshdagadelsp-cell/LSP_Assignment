/* 
    Accept file name and mode from user ( R , W , RW , A ) 
    use access() to check permission for current process
    print accesible not acceible with the reason 

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

    printf(" enter mode to open file accordingly  \n ") ;
    scanf("%s",mode) ;

    
    if ( strcmp ( mode , "O_CREAT" ) == 0 )
    {
        fd = open (fName , O_CREAT , 0777 ) ;
    }
    else if ( strcmp ( mode , "O_RDWR" ) == 0 )
    {
        fd = open ( fName , O_RDWR ) ;
    }
    else if ( strcmp ( mode , "O_RDONLY" ) == 0 )
    {
        fd = open ( fName , O_RDONLY ) ;
    }
    else if ( strcmp ( mode , "O_WRONLY" ) == 0 )
    {
        fd = open ( fName , O_WRONLY ) ;
    }
    else if ( strcmp ( mode , "O_APEND" ) == 0 )
    {
        fd = open ( fName , O_RDWR | O_APPEND  ) ;
    }
   

    if (fd == -1  | fd == 0 )
    {
        perror(" \n" ) ;
    }
    else 
    {
        printf(" file opeened sucessfuly with fd : %d \n ",fd ) ;
    }


    iRet = access ( fName ,  W_OK  | R_OK ) ;

    if ( iRet == -1 )
    {
        printf(" not accesible by process \n " ) ;
    }
    else 
    {
        printf(" accesible by process \n  " ) ;
    }



    close (fd) ;

    return 0 ; 
}