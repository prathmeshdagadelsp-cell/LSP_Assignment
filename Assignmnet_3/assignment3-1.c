/*
     copy file content source to destination 

     create destination if not exist 

     copy  using buffer read () and write ()
    
   

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

    char dName2 [256] ;
    char dName1 [256] ;
      char Buffer [4096] ;
  
      memset (Buffer , '\0' , sizeof(Buffer) ) ;
     bool bFlag = false ;

    int iRet = 0 , fd1 = 0 ,fd2 = 0  , i = 0  ; 
    

    printf(" enter source file name to open \n ") ;
    scanf("%s",dName1) ;

    printf(" enter destination file name to open   \n ") ;
    scanf("%s",dName2) ;



    fd1 = open (dName1 , O_RDWR ) ;
    fd2 = open (dName2 , O_RDWR | O_CREAT , 0777  ) ;

    
    if ( fd1 == -1 || fd2 == -1 )
    {
      perror(" \n" ) ;
      return -1 ;
    }

        iRet =  fstat ( fd1  , &obj ) ;
   
        if (iRet == -1 )
        {
            perror (" \n " ) ;
            return -1 ;    
    
        }
        
        iRet = read (fd1 , Buffer , obj.st_size ) ;

        printf(" the no of bytes are read sucessfuly : %d ", iRet ) ;

        iRet =  write (fd2 , Buffer , obj.st_size ) ;

        printf(" the no of bytes are written sucessfuly : %d ", iRet ) ;



       close(fd1) ;
       close(fd2) ;
    
    return 0 ; 
}