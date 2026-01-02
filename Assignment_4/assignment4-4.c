/*

    File merg utility 

    problem statment : 
    merg multiple file into a single file 

    input : 
    output file file1 file2 file3 ....


    output :
    combined file content in order 

    

*/

//  program performs following steps 


# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>


int main ( int index , char * argvs[] )
{

    int outputfd = 0 ; 
    int fd = 0 ;
    char Buffer[4096] ;
    int iRet = 0 ; 
    char bytesinstring[20] ;


    struct stat obj ;

    memset( Buffer , '\0' , sizeof(Buffer)) ;

    outputfd = open (argvs[1] , O_RDWR ) ;

    if ( outputfd == -1 )
    {
        perror(" \n") ;
        return -1 ;
    } 

   
    for ( int i = 2 ; i < index ; i++ )          // i starts from 2 because on 1 output file name as argument 
    {
        fd = open (argvs[i] , O_RDONLY ) ; 

        iRet = fstat( fd , &obj ) ;
        if ( iRet == -1 )
        {
            perror("\n") ;
        } 

        iRet = read ( fd , Buffer , obj.st_size ) ;

        if ( iRet == -1 )
        {
            perror("\n") ;
            return -1 ;
        } 


        sprintf(bytesinstring , "%d", obj.st_size ) ;
    
        write ( outputfd , argvs[i] , strlen(argvs[i])) ;
        write ( outputfd , "\t" , 1 ) ;
        write ( outputfd ,bytesinstring , strlen(bytesinstring)) ;
        write(outputfd , "\n" , 1 ) ;

        iRet = write ( outputfd , Buffer , obj.st_size ) ;
        
        write(outputfd , "\n" , 1 ) ;
 
        memset( Buffer , '\0' , sizeof(Buffer)) ;

        close(fd) ;


    }



    close (outputfd) ;
    

    return 0 ; 
}