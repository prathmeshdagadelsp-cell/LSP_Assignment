/*

    Create a shared library that maintains a global variable inside the library.

    The library should provide functions to:

    Modify the global value 
    
    Display its value

    Reset its value

    Write a dynamically linked client program to demonstrate persistence of the global variable across multiple function call 




*/





#include <stdio.h>
#include <dlfcn.h>

int main() 
{
    void *handle = dlopen("./library.so", RTLD_LAZY);

    if (!handle) 
    {
        printf("Error: %s\n", dlerror());
        return 1;
    }

    void (*increment)();
    void (*display)();
    void (*reset)();

    increment = dlsym(handle, "increment");
    display   = dlsym(handle, "display");
    reset     = dlsym(handle, "reset");

    increment();
    increment();
    display();   // should show 2

    reset();
    display();   // should show 0

    dlclose(handle);

    return 0;
}