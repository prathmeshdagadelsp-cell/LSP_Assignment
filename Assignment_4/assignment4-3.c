/*

    File copy using pread & pwrite  

    problem statment : 
    copy a file using pread () and pwrite () without changing the file offset 

    input : 
    source file destination file neame as command-line arguments 

    output :
    copied file identical to source   

    

*/

# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>


int main ( int index , char * argvs[] )
{

    int sourcefd = 0 ; 
    int destfd = 0 ;
    char Buffer[4096] ;
    int iRet = 0 ; 


    struct stat obj ;

    memset( Buffer , '\0' , sizeof(Buffer)) ;

    sourcefd = open (argvs[1] , O_RDONLY ) ;
    destfd = open ( argvs[2] ,  O_RDWR | O_CREAT , 0777 ) ;

    if ( sourcefd == -1 )
    {
        perror(" \n") ;
        return -1 ;
    } 
    if ( destfd == -1 )
    {
        perror(" \n") ;
        return -1 ;
    } 

    iRet = fstat( sourcefd , &obj ) ;
    if ( iRet == -1 )
    {
        perror("\n") ;
    } 
    

    iRet = pread( sourcefd , Buffer , obj.st_size , 0 ) ;

    if (iRet == -1 )
    {
        perror (" \n") ;
        return -1 ;
    }

    iRet = pwrite ( destfd , Buffer , obj.st_size , 0 ) ;

    if (iRet == -1 )
    {
        perror (" \n") ;
        return -1 ;
    }


    close (sourcefd) ;
    close (destfd) ;

    return 0 ; 
}
