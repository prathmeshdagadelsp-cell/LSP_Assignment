/*

    explain the diffrence between RTLD_LAZY and RTLD_NOW flags using with dlopen () 

    write a program that loads the same shared library twice

    once with : RTLD_LAZY ;
    once with RTLD_NOW ; 


    observe and explain the behaviour 

*/



/*    - handle 1 will link with the symbol when it got called        (RTLD_LAZY)
      - handle 2 wil link with symol while opening the so file       (RTLD_NOW)

      - handle 1 opened so file could run existing and could generate with nonexisting functions 
      - handle 2 opened so file will generate error if any missing function symbol is not found  

      - faster 
      - slower 
      
*/

# include <stdio.h>
# include <dlfcn.h>
# include <stdlib.h>


int main ()
{
    int iRet = 0 ; 
    void * handle1 = NULL ;
    void * handle2 = NULL ;

    int (*fp ) (int , int ) ;    // function pointer 


    handle1 = dlopen("./library.so" ,RTLD_LAZY) ;

    handle2 = dlopen("./library.so" ,RTLD_NOW) ;

    
    if ( handle1 == NULL )
    {
        fprintf(stderr , "%s:\n" ,  dlerror() ) ;
        return -1 ;
    }


    if ( handle2 == NULL )
    {
        fprintf(stderr , "%s:\n" ,  dlerror() ) ;
        return -1 ;
    }




    // addition  with handle1 
    fp = ( int (*) (int , int ))dlsym(handle1 , "Addition") ;

    if ( fp == NULL )
    {
        printf(" unable to get adresss of a function \n") ;
        dlclose(handle1) ;   
    }
    iRet = fp ( 11 , 40 ) ;

    printf(" Addition is : %d\n",iRet) ;

    dlclose(handle1) ;



    // addition  with handle2
    fp = ( int (*) (int , int ))dlsym(handle2 , "Addition") ;

    if ( fp == NULL )
    {
        printf(" unable to get adresss of a function \n") ;
        dlclose(handle2) ;   
    }
    iRet = fp ( 11 , 40 ) ;

    printf(" Addition is : %d\n",iRet) ;


    dlclose(handle2) ;


}





