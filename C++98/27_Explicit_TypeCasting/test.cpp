#include <iostream> 

int main(void)
{
    short s; 
    float f = 3.14; 
    int n = 0x0a0b0c0d; 
    double d = 1343535.3666; 
    s = (short)f; 

    std::cout << "s=" << s << std::endl; 

    s = (short)n; 
    std::cout << "s=" << std::hex << s << std::endl;

    s = d; 
    std::cout << "s = " << std::dec << s << std::endl; 

    return 0; 
}

/* 
unsigned long long n; 
void test(void)
{
    *(short*)((char*)&n + 1) = 0xffff;  
}
*/
