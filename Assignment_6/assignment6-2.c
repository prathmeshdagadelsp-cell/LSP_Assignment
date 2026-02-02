/*
    write a c program to demonstrate runtime dynamic linking in linux 

    program should : 

    load a shared libray using dlopen ()

    fetch function adress using dlsym()

    handle errors using dlerror ()

    release the library using dlclose ()


    explain the role of each function used in program 


*/


# include <stdio.h>
# include <dlfcn.h>
# include <stdlib.h>


int main ()
{


    int iRet = 0 ; 
    void * handle = NULL ;

    int (*fp ) (int , int ) ;    // function pointer 


    handle = dlopen("./library.so" ,RTLD_LAZY) ;    // dlopen is used to open a dynamic library which is compiled and usable with .so file returns  NULL on error 


    if ( handle == NULL )
    {
        fprintf(stderr , "%s:\n" ,  dlerror() ) ;  // dlerror it is used to diplay the error happend returns string 
        return -1 ;
    }


    // for addition 
    fp = ( int (*) (int , int ))dlsym(handle , "Addition") ;      // dlsym is used to fetch the adress of symbol (function or variable ) from a dynamiccaly loaded shared object at runtime 

    if ( fp == NULL )
    {
        fprintf(stderr , "%s:\n" ,  dlerror() ) ;
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


    dlclose(handle) ;       // dlclose is used to close the dynamic link throgh which we loaded 


}