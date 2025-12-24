/* 

    write string to file  

    accept file name and string from user  
    write string using write () (append mode bydefault )
    print number of bytes writtten 

*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>


int main ()
{
    char fName [256] ;
    char string[4096] ;
    char Buffer [4096] ;    
    char mode [20] ;
    int fd = 0  , iBytes = 0 , iRet = 0  ; 

    
    printf(" enter file name to open the file \n ") ;
    scanf("%s",fName) ;

    printf(" enter string to write in file  \n ") ;
    scanf(" %[^'\n']s",string) ;


    fd = open ( fName ,  O_RDWR | O_APPEND  ) ;                    
     
    if (fd == -1 )
    {

        perror(" \n" ) ;
        return -1 ;
    }
    else 
    {
        printf(" file opeened sucessfuly with fd : %d \n ",fd ) ;
    }


    iRet  = write ( fd  , string , strlen(string) ) ;

    printf(" the total bytes writtenn are : %d",iRet ) ;


    close(fd) ;

   
    return 0 ; 
}