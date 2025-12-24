/* 

    find largest file in directory 
    find and print its size in bytes 
    consider only regular file  : regular 
    use lstat()    

*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>



int main ()
{
    char fName [256] ;    
    int iRet = 0  ,  lFilesize  = 0  , bytes =  0  ; 
    char largefile [256] ;

    printf(" enter firectory name to open \n ") ;
    scanf("%s",fName) ;


    struct DIR * dir = NULL ;


    struct dirent * entries = NULL ;


    struct stat sobj ;
   

    dir = opendir(fName) ;
                      

    if ( dir == -1 )
    {
        
        perror(" \n" ) ;
        return -1 ;
    }
 

    while ( (entries = readdir(dir)) != NULL )
    {

        if ((strcmp(entries->d_name , ".") == 0 ) || (strcmp(entries->d_name , "..") == 0 ))
        {
            continue ; 
        }

      iRet = stat ( entries->d_name , &sobj ) ;

       if ( iRet == -1 )
        {

            perror(" \n" ) ;
            return -1 ;
        }
        
        if ( strlen(entries->d_name)  > lFilesize  )
        {
        
            lFilesize = lFilesize + strlen(entries->d_name) ;
            strcpy(largefile , entries->d_name) ;
            bytes = sobj.st_size ;

        }
    

    }
    printf(" the largest file is : %s of %d bytes \n ",largefile , strlen(largefile)) ;


    closedir(dir) ;

    return 0 ; 
    

}    
