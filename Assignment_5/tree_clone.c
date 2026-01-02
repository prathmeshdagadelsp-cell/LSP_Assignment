/*

  print a directory as a tree ; 

  root / 
  a.txt 
  src/ 
  ganesh.txt 

*/


#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void printdirectorytree(const char *dirname, int level)
{
    DIR *dir = NULL ;
    struct dirent *entry;
    struct stat st;
    char path[1024];

    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
        {
             continue;
        }
           
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (lstat(path, &st) == -1)
        {
            perror("lstat");
            continue;
        }

        
        for (int i = 0; i < level; i++)
        {
             printf("│   ");
        }
        
        
        if (S_ISDIR(st.st_mode))
        {
            printf("├── %s/\n", entry->d_name);
            printdirectorytree(path, level + 1);
        }
        else if (S_ISREG(st.st_mode))
        {
            printf("├── %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    char cwd[4096] ;
    char * cwdd = &cwd  ; 

    memset ( cwd , '\0' , sizeof(cwd)) ;

    getcwd(cwd, sizeof(cwd) ) ;

    while ( *cwdd != '\0')
    {
        if( *cwdd == '/')
        {
            *cwdd = '\n' ;     
        }
        cwdd++ ;
    }

    cwdd = NULL ;
    cwdd = &cwd ; 
    
    while ( *cwdd != '\0')
    {
        if( *cwdd == '\n')
        {
            printf("/") ;
        }
       
        printf("%c",*cwdd) ;
        
        cwdd++ ;
    }

    printf("/\n") ;
    printdirectorytree(argv[1], 0);

    return 0;
}
