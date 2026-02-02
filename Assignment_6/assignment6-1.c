/* write a program to creat shared library (.so) that contains two functions 


    Addition( int , int ) 

    Substraction (int , int )


    write a seprate client program that loads this library at run time
*/


// library file is : addsub.c
// client file name : assignmet6-1.c


# include <stdio.h>
# include <dlfcn.h>
# include <stdlib.h>


int main ()
{
    int iRet = 0 ; 
    void * handle = NULL ;

    int (*fp ) (int , int ) ;    // function pointer 


    handle = dlopen("./library.so" ,RTLD_LAZY) ;

    if ( handle == NULL )
    {
        fprintf(stderr , "%s:\n" ,  dlerror() ) ;
        return -1 ;
    }


    // for addition 
    fp = ( int (*) (int , int ))dlsym(handle , "Addition") ;

    if ( fp == NULL )
    {
        printf(" unable to get adresss of a function \n") ;
        dlclose(handle) ;   
    }
    iRet = fp ( 11 , 40 ) ;

    printf(" Addition is : %d\n",iRet) ;






    // for substraction 
    fp = ( int (*) (int , int ))dlsym(handle , "Substraction") ;
    if ( fp == NULL )
    {
        printf(" unable to get adresss of a function \n") ;
        dlclose(handle) ;   
    }

    iRet = fp ( 11 , 40 ) ;

    printf(" Substraction is : %d\n",iRet) ;


    dlclose(handle) ;


}