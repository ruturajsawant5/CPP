#include <stdio.h> 
#include <stdlib.h> 

/* 
    Problem: 
    Let T be a struct and mem be a name of the member 
    inside struct T. 

    Write a program to compute an offset of mem with 
    respect to struct T. 
    (Ideally, no pointer or instance variable of 
    struct T should be created)
*/

#define OFFSET_OF(Type, Mem)    ((unsigned long long int)(&((Type*)0)->Mem))

struct T 
{
    int a;      
    char b;     
    float c;    
}; 

int main(void)
{
    struct T* pT = 0; 
    unsigned long long int off_c; 

    off_c = (unsigned long long int)&pT->c; 
    printf("off_c = %llu\n", off_c); 

    off_c = 0; 
    printf("off_c = %llu\n", off_c); 
    off_c = (unsigned long long int)&((struct T*)0)->c; 
    printf("off_c = %llu\n", off_c); 

    printf("OFFSET_OF(struct T, a) = %llu\n", OFFSET_OF(struct T, a)); 
    printf("OFFSET_OF(struct T, b) = %llu\n", OFFSET_OF(struct T, b)); 
    printf("OFFSET_OF(struct T, c) = %llu\n", OFFSET_OF(struct T, c)); 
    
    return (0); 
}

/* 
typewise evaluation: 

    pT -> struct T* 
    pT->c -> float 
    &pT->c -> float* 

    0 + offsetof(c with respect to struct T) -> float*

    0 RHS expr 

    typeof(0) -> int 



*/