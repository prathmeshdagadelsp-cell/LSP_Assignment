/*
    check file present in directory 
    accept directoryname and filename 
    check wether that file exisits in that directory 
    print absolute path if found 

*/


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include<dirent.h>
# include <stdbool.h>
#include <limits.h>
#include <stdlib.h>



int main ()
{
    struct stat obj ;

    char fName [256] ;
    char dName [256] ;
  

    bool bFlag = false ;

   
    struct DIR * dir = NULL ;

    struct dirent * entries = NULL ; 


    printf(" enter directory name to open \n ") ;
    scanf("%s",dName) ;

    printf(" enter filename to check wether fiel is present or not  \n ") ;
    scanf("%s",fName) ;



    dir = opendir( dName) ;

    if (dir == -1 )
    {
      perror(" \n" ) ;
      return -1 ;
    }

    while ((entries = readdir(dir)) != NULL )
    {
        if (strcmp(entries ->d_name , fName ) == 0 )
        {
            bFlag = true ;
            break ;
        } 

    }

    if (bFlag == true )
    {

        printf(" the file is present in directory \n " ) ;
        char * absolutepath = realpath(fName , NULL) ;
        printf(" the absolute path is :  %s  \n ",absolutepath) ;

    }
    else 
    {
        printf(" the file is not present in directory \n " ) ;
    }
  
    closedir(dir) ;

    
    return 0 ; 
}