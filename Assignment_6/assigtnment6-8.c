int count_lowercase(char *s) 
{
    int count = 0;
    while (*s) {
        if (*s >= 'a' && *s <= 'z')
            count++;
        s++;
    }
    return count;
}

int count_uppercase(char *s) 
{
    int count = 0;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            count++;
        s++;
    }
    return count;
}

int count_digits(char *s) 
{
    int count = 0;
    while (*s) {
        if (*s >= '0' && *s <= '9')
            count++;
        s++;
    }
    return count;
}