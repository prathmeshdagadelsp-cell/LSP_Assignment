/*
    write a program  to demonstrate what happens when : 

    Avalid Shared library is loaded 

    An invalid or missing function name is passed to dlsym()

    your program shoud gracefully handle errors using dlerror() and print meaningful message

*/

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

        printf("unable to load the library\n") ;
        return -1 ;
    }


    // for addition 
    fp = ( int (*) (int , int ))dlsym(handle , "Addition") ;     //  if invalid or missing function name is passed to dlysm () it returns error as [ undefiend  Symbol ] happens because library not contains such addition function adress 

    if ( fp == NULL )
    {
       fprintf(stderr , "%s:\n" ,  dlerror() ) ;    // if incase function name is not matched error will be generated inside dlerror also for 1st parameter  
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