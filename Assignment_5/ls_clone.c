/*

write a program thst takes one directory path and print : 

- Entry Name 

- Type ( file / link / other )

- size (bytes) 

-permissions in rwxr-xr-x format 

- last modified time 

-skip . , .. 

- Build full path using snprintf ( dir + '/' + name ) ;


*/



# include <stdio.h> 
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <string.h>
#  include <time.h>


int main ( int index , char *argvs[] )
{

    time_t timestamp ;
    int iRet =  0 ; 
    char buffer[50] ;

    struct DIR * dir = NULL ;
    struct dirent * entries = NULL ; 
    
    dir = opendir(argvs[1]) ;

    if ( dir == -1 )
    {
        perror(" \n ") ;
        return -1 ;
    }

    struct tm  * lastmodifiedtime ;  
    struct stat obj ;
   

    while ((entries = readdir(dir)) != NULL )
    {


        iRet = lstat ( entries->d_name , &obj ) ;
        
        timestamp = obj.st_mtime ;

        lastmodifiedtime = localtime(&timestamp) ;

        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", lastmodifiedtime ) ;

        if ( iRet == -1 )   
        {
            perror (" \n ") ;
        }

        if ( (strcmp(entries ->d_name , "." )== 0)  || ( strcmp(entries ->d_name , ".." )== 0 ) )
        {
            continue; 
        }

        
        printf(" Entry Name : %s \n " , entries->d_name ) ;
        
        if (S_ISDIR(obj.st_mode))
        {
            printf(" directory file : \n ") ;
        }
        else if(S_ISREG(obj.st_mode))
        {
            printf(" regular file : \n ") ;
        }
        else if (S_ISLNK(obj.st_mode))
        {
            printf(" link file : \n ") ;
        }
        else if (S_ISCHR(obj.st_mode))
        {
            printf(" char device  file : \n ") ;
        } 
        else if (S_ISBLK(obj.st_mode))
        {
            printf("  block device  file : \n ") ;
        } 

        
        printf(" permissions : ");

        // user permission 
        if (obj.st_mode & S_IRUSR)
        {
            printf(" r ");
        }
        else
        {
            printf(" - ");
        }


        if (obj.st_mode & S_IWUSR)
        {
            printf(" W ");
        }
        else
        {
            printf(" - ");
        }

        if (obj.st_mode & S_IXUSR)
        {
            printf(" x ");
        }
        else
        {
            printf(" - ");
        }

    
        // group permission 

        if (obj.st_mode & S_IRGRP)
        {
            printf(" r ");
        }
        else
        {
            printf(" - ");
        }


        if (obj.st_mode & S_IWGRP)
        {
            printf(" W ");
        }
        else
        {
            printf(" - ");
        }

        if (obj.st_mode & S_IXGRP)
        {
            printf(" x ");
        }
        else
        {
            printf(" - ");
        }


        // other permission 

        if (obj.st_mode & S_IROTH)
        {
            printf(" r ");
        }
        else
        {
            printf(" - ");
        }


        if (obj.st_mode & S_IWOTH)
        {
            printf(" W ");
        }
        else
        {
            printf(" - ");
        }

        if (obj.st_mode & S_IXOTH)
        {
            printf(" x ");
        }
        else
        {
            printf(" - ");
        }

        printf("\n") ;



        printf(" last modified time : %s \n ", buffer) ;


        

    }

    closedir(dir) ;
   
    return 0 ; 

}