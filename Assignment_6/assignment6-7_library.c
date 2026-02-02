#include <stdio.h>

int counter = 0;   // global variable inside library

void increment() 
{
    counter++;
}


void display() 
{
    printf("Counter value: %d\n", counter);
}

void reset() 
{
    counter = 0 ; 
}   