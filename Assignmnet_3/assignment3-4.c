/*
    delete all empty regular files 

    accept directory name 
    delete all regular file with zero data 
    printf file names and count of deleted files 

*/


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include<dirent.h>
# include <stdbool.h>
# include <sys/types.h>



int main ()
{
    struct stat obj ;

    char dName2 [256] ;
    char dName1 [256] ;
    char  buffer [50] ;
 
    bool bFlag = false ;

    int iRet = 0 , fd = 0 , i = 0  ; 

    struct DIR * dir1 = NULL ;
   


    struct dirent * entries = NULL ; 
   
    
    printf(" enter source directory name to open \n ") ;
    scanf("%s",dName1) ;


    dir1 = opendir( dName1 ) ;
  
    
    if (dir1 == -1 )
    {
      perror(" \n" ) ;
      return -1 ;
    }

    while ((entries = readdir(dir1)) != NULL )
    {


        if (( strcmp(entries ->d_name , ".")== 0 ) ||  ( strcmp(entries ->d_name , "..")== 0 ))
        {
            continue; 
        }

        iRet = stat(entries->d_name , &obj ) ;

    
          if (iRet == -1 )
        {
            
            perror (" \n " ) ;
            return -1 ; 
        }
      
        if (S_ISREG (obj.st_mode))
        {
            
            if ( obj.st_size == 0 )
            {
                i++ ;
                printf(" the unlinked file name is : %s \n ", entries ->d_name) ;
                unlink(entries->d_name) ;
            }
           
        }


    
        
    }

  
    printf(" the count of deleted file are : %d \n " ,i) ;

    

    return 0 ; 

}
