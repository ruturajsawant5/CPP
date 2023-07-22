#include <iostream> 

int f(int n);   // while calling f(), the caller must supply 
                // the actual parameter, otherwise the call will fail 

void g(int m = 0);  // m is a default parameter 
                    // if the client supplies the value for 
                    // m at the time of call then the default 
                    // value zero will be overridden to the caller
                    // supplied value 

void h(int m, int n, int p=0, int q=-1); 

class X
{
    private: 
        int m, n; 
    public: 
        void set_m(int _m=500)
        {
            m = _m; 
        }

        void set_n(int _n=1000); 

        void show() { std::cout << "m=" << m << " n=" << n << std::endl; }
}; 

void X::set_n(int _n)
{
    n = _n; 
}


int main(void)
{
    f(10); 
    // f(); // CTE 
    std::cout << "--------------------------" << std::endl; 
    g(); // default value for m will be used 
    std::cout << "--------------------------" << std::endl; 
    g(500); 
    std::cout << "--------------------------" << std::endl; 
    h(100, 200); 
    std::cout << "--------------------------" << std::endl; 
    h(100, 200, 300); 
    std::cout << "--------------------------" << std::endl; 
    h(-100, -200, 0, -300); 
    std::cout << "--------------------------" << std::endl; 
    
    X objX; 
    objX.set_m(); 
    objX.set_n(); 
    objX.show(); 

    return 0; 
}

// Default syntax must be given ONLY WHLILE DECLARING THE FUNCTION 
// NOT WHILE DEFINING 
void g(int m) 
{
    std::cout << "m=" << m << std::endl; 
}

int f(int n)
{
    return n * n; 
}

void h(int m, int n, int p  , int q)
{
    std::cout << "m=" << m << std::endl; 
    std::cout << "n=" << n << std::endl; 
    std::cout << "p=" << p << std::endl; 
    std::cout << "q=" << q << std::endl; 
}