#include <iostream> 

// POINTER TO CONST 

const int * p;   // BSS  (R/W)
int num = 100;  // data (R/W)
const int cnum = 200; // RODATA (R)

int main(void)
{
    int x; // STACK (R/W)
    const int y=300; // STACK(RONLY), R/W for HW AND OS 
    static const int z =400; // RODATA(R) 

    // ALL ARE VALID 
    // THROUGH p YOU ARE NOT ALLOWED TO CHANGE ANY ONE OF THE 
    // FOLLOWING CONST INTEGERS 
    p = &num; 
    p = &cnum; 
    p = &x; 
    p = &y; 
    p = &z; 
    // *p = 300; // CTE 
    return (0); 
}

// int* p; 
// type(p) == int* 
// type(*p) == int

// const int* p 

// type(*p) == const int 

/* Generalisation 

    const T* p; 

    Creates a read write pointer which can store 
    address of object of type T. 

    object of T itself may be read only or read write 
    Through p, it cannot be changed ! 

    p is a pointer to const T. 

*/