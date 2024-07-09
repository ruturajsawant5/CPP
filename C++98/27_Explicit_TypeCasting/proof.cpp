#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct Date{
    int day; 
    int month; 
    int year; 
}; 

int main(void)
{
    struct Date D; 
    struct Date* pDate; 

    void* p = &D; 

    pDate = malloc(sizeof(struct Date)); // proof of void* -> Date* illegal 
    assert(pDate); 

    free(pDate); 
    pDate = NULL; 

    return 0; 
}

/* 
    #define NULL ((void*)0) 
    struct Date* pDate = NULL; 
    struct Date* pDate = 0; 
*/