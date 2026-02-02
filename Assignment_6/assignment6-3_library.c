/* 
    commads to make this as a .so file 
    
    step 1
    gcc -c filename -o filename.o (filename with.o extension)

    step 2
    gcc -shared -o filename.so (.so filename you want to creat) filename.o (this is a file name that you created )

    step 3 
    while dlopen insert this .so file name 

*/

int Addition(int A , int B )
{
    return A + B ;
}

int Substraction (int A , int B )
{
    return A - B ;
}

int Multiplication (int A , int B )
{
    return A * B ;
}

int Division (int A , int B )
{
    return A / B ;
}

