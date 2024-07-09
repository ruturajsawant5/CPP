#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    void* p; 
    /* 
        You can put any virtual address in p 
        If its invalid at the time of dreferencing 
        then segfault. 

        Even if address is valid, the pointer must be 
        type-cast into some defined type before it can be 
        dereferenced. 
    */

   /* 
    type void is a placeholder. 
    C is an annotated typed language. 
    
    So you must write type names at specific places such as 
    formal parameter of a function, data definition statement 
    or return type of function. 

    If you are writing a statement where type annotation is must 
    but there isnt a valid type available for the same, 
    then placeholder type void must be used. 

    therefore, its not a real data type which can be used to allocate 
    memory 

    Declare a sort function accepting array of integers and size of array 
    and returning nothing 

    void sort(int* pa, size_t N); 

    void N; is therefore illegal. 

    Pointer to void has been made legal.

    void* p; 

    p becomes a pointer which can hold address of any type. 
    But as *p will be of type void. 

    *p is illegal. 

    SO whats the use of keeping addr in p if p cannot be derefernced? 

    *(T*)p

    *(T*)p is of the type T and therefore, is legal. 

    char c; 
    short s; 
    int n; 

    void* p; 

    p = &c; 
    *(char*)p; 

    p = &s; 
    *(short*)p; 

    p = &n; 
    *(int*)p; 

   */
}
