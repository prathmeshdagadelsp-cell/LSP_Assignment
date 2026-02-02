/* 

    creat a shared library thqat contains arithmetic functions : 

    Addition 

    Substraction 

    Multiplication 

    Division 

    write a client program that dynamically loads the library and calls the required function based on user choice 

*/


# include <stdio.h>
# include <dlfcn.h>
# include <stdlib.h>


int main ()
{
    int num = 0 ; 
    
    int iRet = 0 ; 
    void * handle = NULL ;

    int (*fp ) (int , int ) ;    // function pointer 


    handle = dlopen("./library.so" ,RTLD_LAZY) ;

    if ( handle == NULL )
    {

      fprintf(stderr , "%s:\n" ,  dlerror() ) ;
      return -1 ;
    }



    printf(" press 1 : Addition , press 2 : Substraction ,  press 3 : Multiplication ,  press 4 : Division \n") ;
    scanf("%d",&num) ;


    if ( num == 1 )      // Addition 
    {
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
    else if ( num == 2 ) // Substraction 
    {

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
    else if ( num == 3 )  // Multiplication 
    {
        fp = ( int (*) (int , int ))dlsym(handle , "Multiplication") ;
        if ( fp == NULL )
        {
            printf(" unable to get adresss of a function \n") ;
            dlclose(handle) ;   
        }

        iRet = fp ( 11 , 40 ) ;

        printf(" Multiplication is : %d\n",iRet) ;

        dlclose(handle) ;
    }
      else if ( num == 4 ) // Division 
    {
        fp = ( int (*) (int , int ))dlsym(handle , "Division") ;
        if ( fp == NULL )
        {
            printf(" unable to get adresss of a function \n") ;
            dlclose(handle) ;   
        }

        iRet = fp ( 11 , 40 ) ;

        printf(" Division is : %d\n",iRet) ;

        dlclose(handle) ;
        
    }
    else 
    {
        printf("wrong input \n") ;
    }


}

