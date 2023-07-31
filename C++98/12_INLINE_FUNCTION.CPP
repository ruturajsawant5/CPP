inline int max(int a, int b)
{
    return a > b ? (a) : (b); 
}

namespace cpa 
{
    inline int max(int x, int y)
    {
        if(x > y)
            return x; 
        return y; 
    }
}

class T
{
    private: 
        int m, n; 
    
    public: 
        T(int _m, int _n) : m(_m), n(_n) {} 

        inline int getm() const 
        {
            return m; 
        }

        inline int getn() const 
        {
            return n; 
        }

        static inline int max(int p, int q)
        {
            return p > q ? (p) : (q); 
        }
}; 

int main(void) 
{
    T t1(100, 200); 
    int k; 

    k = t1.getm(); // t1.m

    return (0); 
}