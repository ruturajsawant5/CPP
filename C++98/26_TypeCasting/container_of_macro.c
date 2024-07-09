#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(Type, Mem)    ((unsigned long long int)(&((Type*)0)->Mem))

struct A 
{
    int a; 
    char b; 
    float c; 
}; 

void test(float* pf); 
void test_1(float* pf);  

int main(void)
{
    struct A inA1 = {10, 'A', 3.14f}, 
             inA2 = {20, 'B', 6.28f}, 
             inA3 = {30, 'C', 9.42f}; 

    puts("Calling test():"); 
    test(&inA1.c); 
    test(&inA2.c); 
    test(&inA3.c); 

    puts("Calling test_1():"); 
    test_1(&inA1.c); 
    test_1(&inA2.c); 
    test_1(&inA3.c); 

    return (0); 
}

/* 
    Precondition: 
        pf contains an address of member c of 
        some instance of struct A
    Postcondition: 
        Print all members of struct A's instance 
        whose c member address is in pf. 
*/
void test(float* pf)
{
    struct A* pA = NULL; 
    pA = (struct A*)((char*)pf - OFFSET_OF(struct A, c)); 
    printf("pA->a = %d, pA->b = %c, pA->c = %.2f\n", 
            pA->a, pA->b, pA->c); 
}

/* 
float* pf; 

pf + k == address in pf + k * 4 

pf - k == address in pf - k * 4 
*/

#define CONTAINER_OF(addr, Type, Mem)   ((Type*)((char*)addr - OFFSET_OF(Type, Mem)))

void test_1(float* pf)
{
    struct A* pA = CONTAINER_OF(pf, struct A, c); 
    printf("pA->a = %d, pA->b = %c, pA->c = %.2f\n", 
            pA->a, pA->b, pA->c); 
}

/* 
    टाइप कास्टिंग : अर्थ, अनर्थ, अन्वयार्थ 
*/