#include <iostream> 

typedef long long ssize_t; 

template <typename T> 
void sort(T* pa, ssize_t N)
{
    ssize_t i, j; 
    T key; 

    for(j=1; j<N; ++j)
    {
        key=pa[j];
        i=j-1; 
        
        while(i>-1 && pa[i]>key)
        {
            pa[i+1]=pa[i]; 
            i=i-1; 
        }

        pa[i+1]=key; 
    }
}

template <typename T> 
void show(T* pa, ssize_t N, const char* msg)
{
    if(msg)
        std::cout << msg << std::endl; 
    
    for(ssize_t i=0; i<N; ++i)
        std::cout << "pa[" << i << "]:" << pa[i] << std::endl; 
}

int main(void)
{
    int ia[10] = {100, 70, 90, 80, 50, 60, 30, 20, 40, 10}; 
    double da[8] = {8.8, 2.1, 5.3, 0.87, -5.4, 23.4, 77.5, 0.0}; 

    show<int>(ia, 10, "Integer array:Before sort:"); 
    sort<int>(ia, 10); 
    show<int>(ia, 10, "Integer array:After sort:"); 

    show<double>(da, 8, "Double array:Before sort:"); 
    sort<double>(da, 8); 
    show<double>(da, 8, "Double array:After sort:"); 

    return (0); 
}

/* 
Exercise: 
Make following algorithm generic with function 
templates. Test them with different types 
    1) MinMax 
    2) Binary Search 
    3) Merge sort 
    4) Quick Sort 
*/