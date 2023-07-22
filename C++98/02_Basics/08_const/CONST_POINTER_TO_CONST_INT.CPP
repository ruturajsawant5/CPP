#include <iostream> 

int n1=100; // data, r/w
const int n2=200; // rodata, ronly for lang, os, hw
const int* const p1 = &n1; // rodata, ronly for lang, os, hw

int main(void)
{
    int n3=300; // stack, r/w
    const int n4=400; // stack, ronly for lang not for os, hw
    static const int n5=500; // rodata, ronly for lang, os, hw 

    const int* const p2 = &n2; // p2, stack, ronly for lang, not for os and hw 
    const int* const p3 = &n3; // p3, stack, ronly for lang, not for os and hw
    const int* const p4 = &n4; // p4, stack, ronly for lang, not for os and hw 
    const int* const p5 = &n5; // p5, stack, ronly for lang, not for os and hw 

    // p1 to p5 cannot point to any other integer 
    // through p1 to p5, no integer cannot be modified 
    // even if its READ / WRITE 

    int n6 = 700; 
    static const int* const p6 = &n6; // p6, rodata, ronly for lang, os, hw 

    return 0; 
}