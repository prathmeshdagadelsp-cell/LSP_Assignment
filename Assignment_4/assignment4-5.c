/*

    reverse file content 

    problem statment : 
    display the content of file in reverse order 

    input : 
    file name 

    output :
    file content printed in reverse order  

    
*/

# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>


int main ( int index , char * argvs[] )
{

    int fd = 0 ; 
   
    char Buffer[4096] ;
    int iRet = 0 ; 


    struct stat obj ;

    memset( Buffer , '\0' , sizeof(Buffer)) ;

    fd = open (argvs[1] , O_RDONLY ) ;
   

    if ( fd == -1 )
    {
        perror(" \n") ;
        return -1 ;
    } 
   
    iRet = fstat( fd , &obj ) ;

    if ( iRet == -1 )
    {
        perror("\n") ;
    } 
    
   iRet = read( fd , Buffer , obj.st_size) ;
   
    if (iRet == -1 )
    {
        perror (" \n") ;
        return -1 ;
    }



    for ( int i = obj.st_size ; i > 0  ; i-- )
    {
        printf("%c",Buffer[i]) ;
    }
    
    close (fd) ;
  

    return 0 ; 
}
