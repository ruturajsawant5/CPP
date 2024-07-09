#include <stdio.h> 
#include <stdlib.h> 

struct A 
{
    unsigned long long int N; 
    int arr[5]; 
}inA = {
        0x1020304050607080, 
        {
            0x12a034b0, 
            0x11223344, 
            0x9b8c7b6a, 
            0xaabbccdd, 
            0xa7c1b7ff
        }
    }; 

struct B 
{
    double x; 
    float y; 
    float z; 
}; 

void show(struct A* pA, const char* msg)
{
    size_t i; 

    if(msg)
        puts(msg); 

    printf("pA->N = %llx\n", pA->N); 
    for(i = 0; i < 5; ++i)
        printf("pA->arr[%llu]:%x\n", i, pA->arr[i]); 
}

int main(void)
{
    show(&inA, "Before casting"); 
    *(short*)&(((struct B*)(&inA))->y) = 0xf0e0; 
    show(&inA, "after casting"); 
    return 0; 
}

/* 
    PRINCIPLE: 

    p->mem 

    Let p be of type T. 
    
    p->mem == 

    Add offset of mem in T, into address in p. 
    And dereference that address, how many bytes? 
    sizeof(typeof(mem in T))

    &p->mem will simply add offset of mem in T into 
    address in p. 

    struct T* p = (struct T*)malloc(sizeof(T)); 

    ((struct T1*)p)->mem

    offset of mem in T1 will be added to address in p. 

    Member named 'mem' may not be present in struct T 
    whose instance is pointed by p. 

    address in struct T which is a the same offset as that 
    of offset of 'mem' in T1 will be accessed. How many bytes 
    after that address will be affected, sizeof(typeof(mem in struct T1))

    assumption: sizeof(struct T) >= 
                offset of mem in struct T1 + sizeof(typeof(mem in struct T1))

    Otherwise the result is undefined. 

*/