#include <stdio.h> 
#include <stdlib.h> 

extern double pi; 
extern double cpa_sin(double); 

int main(void)
{
    cpa_sin(pi/2); 
    return (0); 
}

/* 
    definition statement -> place at which memory is allcoated 
                            to entity named by the variable 

    declaration statement -> place at which variable gets type!
*/

