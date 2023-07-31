#include <cstdio> 
#include <cassert> 

class CPA_int
{
    private: 
        int n; 

    public: 
        CPA_int(int init_n = 0) : n(init_n) {} 

        CPA_int operator+(const CPA_int& cn)
        {
            return CPA_int(n + cn.n); 
        }
        
        CPA_int operator-(const CPA_int& cn)
        {
             return CPA_int(n + cn.n);
        }

        CPA_int operator*(const CPA_int& cn)
        {
             return CPA_int(n + cn.n);
        }   

        CPA_int operator/(const CPA_int& cn)
        {
            assert(cn.n != 0); 
            return CPA_int(n / cn.n); 
        }

        CPA_int operator&(const CPA_int& cn)
        {
             return CPA_int(n & cn.n);
        }

        CPA_int operator|(const CPA_int& cn)
        {
            return CPA_int(n | cn.n);
        }

        CPA_int operator^(const CPA_int& cn)
        {
            return CPA_int(n ^ cn.n);
        }

        CPA_int operator<<(const CPA_int& cn)
        {
            return CPA_int(n << cn.n);
        }

        CPA_int operator>>(const CPA_int& cn)
        {
            return CPA_int(n >> cn.n);
        }
}; 