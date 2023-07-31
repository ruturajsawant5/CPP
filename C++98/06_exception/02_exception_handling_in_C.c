#include <stdio.h> 
#include <stdlib.h> 
#include <setjmp.h>

#define NEGATIVE_NUMBER_ERROR 2 

jmp_buf buffer; 

double cpa_sqrt(double x); 

int main(void)
{
    double sqrt_x; 
    int ret; 

    ret = setjmp(buffer); 
    if(ret == NEGATIVE_NUMBER_ERROR)
    {
        printf("Square root of negative number cannot be computed\n"); 
        printf("Survived\n"); 
        goto out; 
    }

    sqrt_x = cpa_sqrt(-30); 

    out: 
        printf("Moving forward\n"); 

    exit(0); 
}

double cpa_sqrt(double x)
{
    if(x < 0)
        longjmp(buffer, NEGATIVE_NUMBER_ERROR); 

    return 0.0; 
}
