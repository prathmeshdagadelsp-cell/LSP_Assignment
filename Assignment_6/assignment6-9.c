#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("./library.so", RTLD_LAZY);
    if (!handle) {
        printf("dlopen error: %s\n", dlerror());
        return 1;
    }

    // Array of function pointers: each takes (int,int) returns int
    int (*funcs[3])(int, int);

    funcs[0] = (int (*)(int,int)) dlsym(handle, "add");
    funcs[1] = (int (*)(int,int)) dlsym(handle, "sub");
    funcs[2] = (int (*)(int,int)) dlsym(handle, "mul");

    int a = 10, b = 5;

    for(int i=0; i<3; i++) {
        printf("Function address: %p, Result: %d\n", (void*)funcs[i], funcs[i](a,b));
    }

    dlclose(handle);
    
    return 0;
}