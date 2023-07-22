#include <iostream> 

const int gc_num = 100; // rodata 

int main(void)
{
    const int lc_num = 200; // stack 
    static const int lc_static_num = 300; // rodata 
    int* p = 0; 

    p = &gc_num; // Compile Time Error (CTE)
    p = &lc_num;  // CTE 
    p = &lc_static_num;  // CTE 

    return 0; 
}