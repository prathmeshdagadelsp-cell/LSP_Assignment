# include <stdio.h>
 # include<add.h>

int main ()
{
    int A  = 0 ; 
    int B = 0 ; 
    int Ans = 0 ;

    scanf("%d%d",&A,&B) ;


    Ans = add(A,B) ;
    printf("Addition is %d\n",Ans) ;

    Ans = sub(A,B) ;
    printf("substraction is %d\n",Ans) ;

    Ans = mul(A,B) ;
    printf("Multiplication is %d\n",Ans) ;

    Ans = div(A,B) ;
    printf("Division is %d\n",Ans) ;

    return 0 ; 
}