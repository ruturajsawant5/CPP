#include <iostream> 

int n1=100;         //  DATA SECTION R/W
int* const p1=&n1;  //  RODATA  


const int x1 = 100; // const for compiler and OS & HW

int main(void)
{
    int* const p2 = &n1;    // STACK: p2 is const pointer for compiler 
                            // NOT for OS and HW 
    static int* const p3 = &n1; // RODATA: p3 is a const pointer for 
                                // compiler as well as OS & HW 

    const int x2 = 200;     // const for compiler & not for OS and HW 
    static const int x3 = 300; // const for compiler as well as OS & HW 

   //  int *const y1 = &x1; // ERROR , CTE 
   //  int *const y2 = &x2; // ERROR , CTE 
   //  int *const y3 = &x3; // ERROR , CTE 

    return (0); 
}

/* 
    int* const p1 = &n1; 

    p1 is const pointer to int

    type (*p1)  == integer 
*/