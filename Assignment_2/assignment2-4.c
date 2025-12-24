/* 

    list all file with type
    accept directoryname 
    print each entry with its type : regular / directory / link / fifo / socket / char / block 
    use lstat()    

*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>


int main ()
{
    char fName [256] ;
   
    int iRet = 0 ; 

    printf(" enter firectory name to open \n ") ;
    scanf("%s",fName) ;

   
    struct DIR * dir = NULL ;

    struct dirent * entries = NULL ;

    struct stat obj ;


    dir = opendir(fName) ;
                      

     
    if ( dir == -1 )
    {
        
      perror(" \n" ) ;
      return -1 ;

    }
 
  

    while ( entries = readdir(dir) )
    {


       
      iRet = lstat ( entries->d_name , &obj ) ;

      if ( iRet == -1 )
    {
        
      perror(" \n" ) ;
      return -1 ;

    }


      if (  S_ISREG(obj.st_mode) )
      {
        printf(" the file is regular file \n ") ;
      }
      else if (  S_ISDIR(obj.st_mode) )
      {
        printf(" the file is directory file \n ") ;
      }
      else if (S_ISLNK(obj.st_mode))
      {
        printf(" the file is symbolic file \n ") ;
      }
      else if (S_ISFIFO(obj.st_mode))
      {
        printf(" it is fifo file \n ") ;
      }
      else if (S_ISCHR(obj.st_mode))
      {
        printf(" it is char divice file  \n ") ;
      }
      else if (S_ISBLK(obj.st_mode))
      {
        printf(" it is blk device file \n ") ;
      }
    

        if ((strcmp(entries->d_name , ".") == 0 ) || (strcmp(entries->d_name , "..") == 0 ))
        {
            continue ; 
        }
       printf("the directories are : %s \n  ",entries->d_name ) ;

    }


   closedir(dir) ;    


    return 0 ; 
}