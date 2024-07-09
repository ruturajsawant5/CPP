#include <iostream> 
#include <cstdlib> 



int main(void)
{
    unsigned short s = 10; 
    int num = 0xa0b0c0d0;
    
    std::cout << "s=" << std::hex << s << std::endl; 
    s  = static_cast<int>(num); 
    std::cout << "s=" << std::hex << s <<  std::endl; 
    
    return 0; 
}
