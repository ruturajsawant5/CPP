#include <iostream> 

int main(void)
{
    std::size_t N; 

    std::cout << "Enter size of array:"; 
    std::cin >> N; 

    int* pa = new int[N]; 
    for(std::size_t i=0; i != N; ++i)
        pa[i] = (i+1) * 100; 

    delete[] pa; 
    pa = 0;

    return EXIT_SUCCESS; 
}