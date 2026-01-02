/*

    File copy with offset 

    problem statment : 
    copy a file starting from given byte offset of the sourcefile  

    input : 
    source file destination file and offset as command-line arguments 


    output :
    partial file copied starting from offset  

    

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
    

    lseek ( sourcefd  , atoi(argvs[3]) , SEEK_CUR ) ; 

    iRet = read ( sourcefd , Buffer , obj.st_size - atoi(argvs[3])) ;

    if (iRet == -1 )
    {
        perror (" \n") ;
        return -1 ;
    }

    iRet = write ( destfd , Buffer , obj.st_size - atoi(argvs[3])) ;

    if (iRet == -1 )
    {
        perror (" \n") ;
        return -1 ;
    }


    close (sourcefd) ;
    close (destfd) ;

    return 0 ; 
}


