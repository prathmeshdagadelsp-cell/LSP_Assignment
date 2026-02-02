#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("Usage: %s <shared_library_path> <symbol_name>\n", argv[0]);
        return 1;
    }

    char *lib_path = argv[1];
    char *symbol_name = argv[2];

    // Load shared library
    void *handle = dlopen(lib_path, RTLD_LAZY);
    if (!handle) 
    {
        printf("dlopen error: %s\n", dlerror());
        return 1;
    }

    // Clear any existing errors
    dlerror();

    // Lookup the symbol
    void *sym_addr = dlsym(handle, symbol_name);
    char *error = dlerror();
    if (error != NULL) {
        printf("Symbol '%s' not found: %s\n", symbol_name, error);
    } else {
        printf("Symbol '%s' found at address: %p\n", symbol_name, sym_addr);
    }

    dlclose(handle);
    return 0;
}