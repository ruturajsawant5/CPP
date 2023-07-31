#include <iostream> 

/* f -> function template */
template <int N>
void f()
{

}

/* C -> class template */
template <int M>
class C
{

}; 

/* 
    function template != function 
    function can be generated from function 
    template using a process called function template instantiation 

    Class template != Class 

    Class can be generated class template 
    using a process called class template instantiation 
*/ 

/* Using parameter in template parameter list 
    in function / class defined below it 
*/

/* 1. Non-type parameter */

template <int N> 
void f(void)
{
    /* N can be used as r-value */
    int* pa = malloc(N * sizeof(int)); 
    assert(pa != NULL); 
}

