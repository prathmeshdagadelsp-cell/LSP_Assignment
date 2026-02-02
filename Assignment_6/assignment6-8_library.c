#include <stdio.h>
#include <dlfcn.h>
# include <stdlib.h>

int main() 
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    void *handle = dlopen("./library.so", RTLD_LAZY);
    if (!handle) {
        printf("dlopen error: %s\n", dlerror());
        return 1;
    }

    int (*count_lowercase)(char *);
    int (*count_uppercase)(char *);
    int (*count_digits)(char *);

    count_lowercase = (int (*)(char *)) dlsym(handle, "count_lowercase");
    count_uppercase = (int (*)(char *)) dlsym(handle, "count_uppercase");
    count_digits    = (int (*)(char *)) dlsym(handle, "count_digits");

    printf("Lowercase letters: %d\n", count_lowercase(str));
    printf("Uppercase letters: %d\n", count_uppercase(str));
    printf("Digits: %d\n", count_digits(str));


    dlclose(handle);

    return 0;
}