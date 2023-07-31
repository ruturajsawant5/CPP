#include <iostream> 

class cpa_int 
{
    private: 
        int n; 

    public: 
        cpa_int(int _n = 0) : n(_n) {} 

        cpa_int& operator+(const cpa_int& other)
        {
            return *new cpa_int(n + other.n); 
        }
}; 

int main(void)
{
    cpa_int n1(100), n2(200); 

    cpa_int& ref_sum = n1 + n2; 
    
    // use ref_sum
    delete &ref_sum; 
    
    return 0; 
}