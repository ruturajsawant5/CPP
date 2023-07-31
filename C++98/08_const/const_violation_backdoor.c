#include <stdio.h> 
#include <stdlib.h> 

const int gc_num = 100; 

int main(void) 
{
    const int lc_num = 200; 
    int* p = NULL; 

    printf("lc_num = %d\n", lc_num); 
    p = &lc_num; 
    *p = 2000; // WORKS
    printf("lc_num = %d\n", lc_num); 
    
    printf("gc_num = %d\n", gc_num); 
    p = &gc_num; 
    *p = 1000; // FAILS 
    printf("gc_num = %d\n", gc_num); 

    return (0); 
}

