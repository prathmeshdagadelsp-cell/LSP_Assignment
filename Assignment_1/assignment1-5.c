/* 
    read n bytes from file   
    Accept file name and n number of bytes 
    read exactly n bytes using read () and print on console 
    if file contains less than n print only available bytes 

*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

int main ()
{
    char fName [256] ;
    char Buffer [4096] ;    
    char mode [20] ;
    int fd = 0  , iBytes = 0 , iRet = 0  ; 

        
    printf(" enter file name to open the file \n ") ;
    scanf("%s",fName) ;

    printf(" enter number of bytes you want to read \n ") ;
    scanf("%d",&iBytes) ;


    fd = open ( fName ,  O_RDONLY ) ;

    if (fd == -1 )
    {
        perror(" \n" ) ;
    }
    else 
    {
        printf(" file opeened sucessfuly with fd : %d \n ",fd ) ;
    }
 
    iRet = read (fd , Buffer , iBytes ) ;

    
    printf(" the no of data from file is : %s ",Buffer) ;


   
    return 0 ; 
}