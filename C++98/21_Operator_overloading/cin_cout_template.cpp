#include <iostream> 

class T 
{
    private: 
        // object data layout 
    public: 
        friend std::ostream& operator<<(std::ostream& os, const T& objT); 
        friend std::istream& operator>>(std::istream& is, const T& objT);
}; 

std::ostream& operator<<(std::ostream& os, const T& objT)
{
    // memberwise output of objT 
    return os; 
}

std::istream& operator>>(std::istream& is, const T& objT)
{
    // memberwise input of objT 
    return is; 
}

int main(void)
{
    T t1, t2; 

    std::cin >> t1 >> t2; 
    std::cout << t1 << t2; 

    return 0; 
}