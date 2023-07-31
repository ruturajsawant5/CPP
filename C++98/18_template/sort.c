#include <stdio.h> 

typedef long long ssize_t; 

void cpa_sort(int* pa, size_t N);

void sort_int(int* pa, ssize_t N); 
void sort_double(double* pa, ssize_t N); 

int main(void)
{
    int a[6] = {50, 60, 40, 30, 10, 20}; 
    int b[6] = {100, 20, 300, 400, 54, 21}; 

    float fa[4] = { 1.1f, 3.3f, 2.2f, 4.4f}; 
    double da[6] = {10.10, 5.5, 3.3, 2.2, 8.8}; 

    cpa_sort(a, 6); 
    cpa_sort(b, 6); 

    cpa_sort(fa, 4); 
    cpa_sort(da, 6); 

    return (0); 
}


void cpa_sort(int* pa, size_t N)
{
    puts("In sorting"); 
    /* Some sorting algorithm */
}

/* Insertion sort */
void sort_int(int* pa, ssize_t N)
{
    ssize_t i, j; 
    int key; 

    for(j=1; j < N; ++j)
    {
        key = pa[j]; 
        i = j - 1; 
        
        while(i > -1 && pa[i] > key)
        {
            pa[i+1] = pa[i]; 
            i = i - 1; 
        }

        pa[i+1] = key; 
    }
}

void sort_double(double* pa, ssize_t N)
{
    ssize_t i, j; 
    double key; 

    for(j=1; j < N; ++j)
    {
        key = pa[j]; 
        i = j - 1; 
        
        while(i > -1 && pa[i] > key)
        {
            pa[i+1] = pa[i]; 
            i = i - 1; 
        }

        pa[i+1] = key; 
    }
}

/* 
    Logic of sorting array is independent of 
    array element type! 
*/

void generic_sort(void* pa, size_t N)
{
    /* 
        pa[i] cannot be interpreted by compiler 
        This approach will not work! 
    */


}