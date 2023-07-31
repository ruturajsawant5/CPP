#include <iostream> 

class Wrapper
{
    private: 
        int (*pfn)(int, int); 

    public: 
        Wrapper(int(*_pfn)(int, int)) : pfn(_pfn) {} 
        
        int operator()(int m, int n)
        {
            return pfn(m, n); 
        }
}; 

int my_add(int x, int y) { return x + y; }

void test(Wrapper& w); 

int main(void)
{
    Wrapper w(my_add); 

    test(w); 

    return (0); 
}

void test(Wrapper& w)
{
    int rs = w(100, 200); 
    std::cout << "rs:" << rs << std::endl; 
}