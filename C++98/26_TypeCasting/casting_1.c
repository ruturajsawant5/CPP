#include <stdio.h> 
#include <stdlib.h> 

int n = 0x12a2b1c8; 

int main(void)
{
    unsigned char uc1, uc2, uc3, uc4; 

    uc1 = *(unsigned char*)&n; 
    uc2 = *(unsigned char*)((unsigned char*)&n + 1); 
    uc3 = *(unsigned char*)((unsigned char*)&n + 2); 
    uc4 = *(unsigned char*)((unsigned char*)&n + 3); 

    printf("uc1 = %hhx, uc2 = %hhx, uc3 = %hhx, uc4 = %hhx", 
            uc1, uc2, uc3, uc4); 

    return (EXIT_SUCCESS); 
}

/* 
    uc1 = *(unsigned char*)&n; 

    n: int 
    &n: int* 

    *(&n); 
    &n == x 

    *(&n)   M[x:x+3]

    *(unsigned char*)&n
    M[x] 

    Little Endian representaiton 
    1000:   [c8]
    1001:   [b1]
    1002:   [a2]
    1003:   [12]

    Big endian representation 
    1000:   [12]
    1001:   [a2]
    1002:   [b1]
    1003:   [c8]
///////////////////////////////////////////////statement 1 is over 

    As the intel is a little endian machine we will proceed with 
    the little endian representation of multi-byte integers. 

    int n = 0x12a2b1c8; 

    Little Endian representaiton 
    1000:   [c8]
    1001:   [b1]
    1002:   [a2]
    1003:   [12]

    n: int 
    &n: int* 
    (unsigned char*)&n

    Why was this done? 

    Let p be a pointer to type T. 
    T* p. 

    p + 1 is defined as address in p + sizeof(T)
    p - 1 is defined as address in p - sizeof(T)

    p + k = address in p + k * sizeof(T)
    p - k = address in p - k * sizeof(T)

    n -> int 
    &n -> int* 
    &n + 1 == address of n, say x, + 4 == x + 4 

    I want to go to x + 1 

    How should I think? 
    What should have been the address of n that would have 
    resulted in evaluation of &n + 1 into x + 1? 

    Answer is any one byte data type: char, unsigned char 

    (unsigned char*)&n + 1 

    address of n + 1 == address evaluate 

    x + 1 does not have any inherent type of its own! 

    Before, dereferencing x + 1, I must assign a type to it. 
    How to do that? 

    Type cast expression resulting into x + 1 into desired type. 

    I want to read only 1 byte from x + 1. 
    Therefore, I will prefer type of x + 1 to be unsigned char. 

    uc2 = *(unsigned char*)((unsigned char*)&n + 1); 



*/