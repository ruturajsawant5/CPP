#include <iostream> 
#include <stdexcept>

template <typename T> 
T max(T a, T b)
{
    T m; 

    if(a > b)
        m = a; 
    else 
        m = b; 

    return (m); 
}

int main(void)
{
    int max_element = max<int>(100, 200); 
    std::cout << "Max:" << max_element << std::endl; 
    return (0); 
}