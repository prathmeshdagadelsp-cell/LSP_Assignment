/* 
    Accept file name from user and open it using open ().
    print : Sucess message + returned file discriptor 
    Handle errors using perror() 

*/


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>


int main ()
{
    char fName [256] ;  
    int fd = 0 ; 
    memset(fName , '\0' , sizeof(fName)) ;
    

    printf(" enter file name to open the file \n ") ;
    scanf("%s",fName) ;

    fd = open (fName , O_RDWR  ) ;

    if (fd == -1 )
    {
        perror(" \n ") ;
    }
    else 
    {
        printf(" Sucessfuly opened file with fd of : %d \n ",fd ) ;
    }

    close (fd) ;

    return 0 ; 
}