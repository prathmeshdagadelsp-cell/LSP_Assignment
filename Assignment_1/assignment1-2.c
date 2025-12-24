/* 
    Accept file name and mode from user ( R , W , RW , A ) 
    convert mode to flags (O_RDONLY , O_WRONLY , O_RDWR , O_APPEND | O_CREAT)
    convert mode to flags  

*/


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>


int main ()
{
    char fName [256] ;  
    char mode [20] ;
    int fd = 0 ; 

    
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

    if (fd == -1 )
    {
        perror(" \n" ) ;
    }
    else 
    {
        printf(" file opeened sucessfuly with fd : %d \n ",fd ) ;
    }


    close (fd) ;

    return 0 ; 
    
}  