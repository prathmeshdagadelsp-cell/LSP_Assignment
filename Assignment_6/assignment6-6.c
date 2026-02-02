/*
    write a program to demonstrate dynamic search path resolution in linux 

    place a shared library in custom directory 

    write a client program that loads the library without specifying fullpath 

    execute the program with and without setting LD_LIBRARY_PATH     


explain the output in both cases 

*/

# include <stdio.h>
# include <dlfcn.h>
# include <stdlib.h>


int main ()
{
    int iRet = 0 ; 
    void * handle = NULL ;

    int (*fp ) (int , int ) ;    // function pointer 


    handle = dlopen("library.so" ,RTLD_LAZY) ;

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

    dlclose(handle) ;
}    



/* 
    normal compilation and execution 
    in first normal execution 
    l Error generated library.so: cannot open shared object file: No such file or directory:
    it is enable to find the so file 
 



    In second execution 
    after complile use commmand 
    command : export LD_LIBRARY_PATH=/home/prathmesh/mylibs
    and  the execute

    output is visible 

    after compilation if a path is not specified we must use LD_LIBRARY_PATH which helps find the so file and then if execute output is visible 

*/