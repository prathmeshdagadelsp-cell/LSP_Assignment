/* 

    list all files from directory 
    accept directoryname 
    use opendir () / readdir() to print names (skip . / .. )  
    

*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>


int main ()
{
    char fName [256] ;
   

    printf(" enter firectory name to open \n ") ;
    scanf("%s",fName) ;

   
    struct DIR * dir = NULL ;

    struct dirent * entries = NULL ;


    dir = opendir(fName) ;
                      

     
    if ( dir == -1 )
    {
        
        perror(" \n" ) ;
        return -1 ;
    }
 

    while ( entries = readdir(dir) )
    {
        if ((strcmp(entries->d_name , ".") == 0 ) || (strcmp(entries->d_name , "..") == 0 ))
        {
            continue ; 
        }
       printf("the directories are : %s \n  ",entries->d_name ) ;
    }


    closedir(dir) ;

   
    return 0 ; 
}