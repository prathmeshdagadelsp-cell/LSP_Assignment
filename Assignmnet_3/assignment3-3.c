/*
    move all files dir -> dir 
    
    accept source directory and destination directory 
    move all regular file 

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

    int iRet = 0 , i = 0  ; 

    struct DIR * dir1 = NULL ;
    struct DIR * dir2 = NULL ;


    struct dirent * entries = NULL ; 
   
    
    printf(" enter source directory name to open \n ") ;
    scanf("%s",dName1) ;

    printf(" enter destination directory name to open   \n ") ;
    scanf("%s",dName2) ;


    strcpy ( buffer , dName2) ;

    

   
    dir1 = opendir( dName1 ) ;
    dir2 = opendir( dName2 ) ;

    
    if (dir1 == -1 || dir2 == -1 )
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

        iRet = lstat(entries->d_name , &obj ) ;



        sprintf(&buffer[strlen(dName2 )] , entries->d_name ) ;


        if (S_ISDIR (obj.st_mode))
        {
            continue ;

        }
        else if (S_ISREG (obj.st_mode))
        {
            i++ ;
            iRet =  rename(  entries->d_name , buffer ) ;
        }

         if (iRet == -1 )
        {
            
            perror (" \n " ) ;
            return -1 ; 
        }

        
    }

  
    printf(" the count of moved file are : %d \n " ,i) ;


    closedir(dir1) ;
    closedir(dir2) ;

    
    return 0 ; 
}
