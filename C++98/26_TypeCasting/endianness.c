#include <stdio.h> 
#include <stdlib.h> 

/* 
    int num = 0x0a0b0c0d; 
    &num is ALWAYS going to be the lowest addres: 

    Least addr == least significant byte = little endian 
    Least addr == most significant byte = big endian  

    x       x+1     x+ 2    x+3 
    0d      0c      0b      0a   ---> LITTLE 
    0a      0b      0c      0d   ---> BIG 

    x+3        x+2        x+1        x 
    0a          0b         0c        0d  ---> LITTLE 
    0d          0c         0b        0a  ---> BIG 

    N integer value     ->  4 byte? 

    N -> hex -> prefix LHS zeros as required 
    8 digit hex 

    [   ][  ][  ][  ]

*/

int main(void)
{
    int num = 0x0a0b0c0d; 
    unsigned char uc; 
    
    uc = *(unsigned char*)&num; 

    if(uc == 0xd)
        puts("Little endian machine"); 
    else if(uc == 0xa)
        puts("Big endian machine"); 
    else 
        puts("Strange machine"); 

    return (EXIT_SUCCESS); 
}