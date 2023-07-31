#include <cstdio>

class cpa_int
{
    private: 
        int n; 

    public: 
        cpa_int(int _n=0) : n(_n) {} 
        cpa_int& operator+(const cpa_int& other)
        {
            return *new cpa_int(n + other.n); 
        }
        void show() const 
        {
            printf("n=%d\n", n); 
        }
}; 

int main(void)
{
    cpa_int M(10), N(11), K(100); 

    M.show(); 
    N.show(); 
    N = M + N + K;
    M.show(); 
    N.show(); 

    return 0;  
}

// Operator Overloading theory -> along with rationale 
// binary operator overloading: T*T->T, T*T'->T, T*T->T'
// binary operator overloading: general approach 
// Unary operator overloading : general approach, !,~, pre/post incr/decr
// return object by instance, pointer or reference 

// std::cout, std::cin 
// [], ()

