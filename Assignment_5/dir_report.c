/*

   file counter + sizereport  

 - total number of files 
 - total number of directories 
 - total size of regular file ( in bytes ) 
 - largest filename + size 
 

*/


# include <stdio.h> 
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <string.h>
#  include <time.h>
# include <string.h>


int main ( int index , char *argvs[] )
{

    char Largestfile [100] ;
    int  largestfilesize = 0 ;
    int totalfiles = 0  ;  
    int totaldirectories = 0 ; 
    int totalsizeofregfiles = 0 ;  


    memset(Largestfile , '\0' , sizeof(Largestfile) ) ;

    int iRet =  0 ; 
  
    struct stat obj ;
    struct DIR * dir = NULL ;
    struct dirent * entries = NULL ; 
    
    dir = opendir(argvs[1]) ;

    if ( dir == -1 )
    {
        perror(" \n ") ;
        return -1 ;
    }

    while ((entries = readdir(dir)) != NULL )
    {

        iRet = lstat ( entries->d_name , &obj ) ;
        

        if (S_ISLNK(obj.st_mode))
        {
          continue ; 
        }

        if ( iRet == -1 )   
        {
            perror (" \n ") ;
        }
        
        if ( strlen(entries->d_name) > strlen(Largestfile))
        {
            strcpy(Largestfile , entries->d_name ) ;
            largestfilesize = obj.st_size ; 
        }
        
       
        if (S_ISDIR(obj.st_mode))
        {
           totaldirectories++ ;
        }
        else if(S_ISREG(obj.st_mode))
        {
            totalsizeofregfiles = obj.st_size + totalsizeofregfiles ;
            totalfiles++ ;
        }

      
    }

        closedir(dir) ;


        printf(" total number of files are : %d \n ",totalfiles ) ;
        printf(" total number of directories : %d \n ",totaldirectories+1) ;
        printf("total size of regular files : %d \n ",totalsizeofregfiles) ;
        printf(" the largest file is : %s of has %d  \n bytes ",Largestfile,largestfilesize) ;


   
    return 0 ; 

}

