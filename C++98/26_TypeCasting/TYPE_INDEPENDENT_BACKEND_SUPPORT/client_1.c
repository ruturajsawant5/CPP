#include <stdio.h> 
#include <stdlib.h> 

#include "wrapper.h"

struct array
{
    int* p_arr; 
    int N; 
}; 

int* my_func(struct array* p_arr); 

int main(void)
{
    int* p_ret; 
    int a[5] = {10, 20, 30, 40, 50}; 
    struct array A = {a, 5}; 

    register_function(my_func); 
    call_function(&A); 
    get_return_value(&p_ret); 

    printf("result = %d\n", *p_ret); 
    free(p_ret); 
    p_ret = NULL; 

    return (0); 
}

int* my_func(struct array* p_arr)
{
    int* result = (int*)malloc(sizeof(int)); 
    assert(result != NULL); 
    int i; 

    *result = 0; 
    for(i = 0; i < p_arr->N; ++i)
        *result = *result + p_arr->p_arr[i]; 

    return result; 
}

/* 
    register_function(my_func); 
    call_function(&A); 
    get_return_value(&p_ret); 

    void register_funcion(int*(*pfn)(struct array*)); 
    void call_function(struct array&); 
    void get_return_value(int** pp_ret); 
*/