#include <iostream> 

class T
{
    private: 
        int m, n; 

    public: 
        T(int _m, int _n) : m(_m), n(_n) {} 

        int getm() const { return m; }
        int getn() const { return n; }
        void show() const { std::cout << "m=" << m << " n=" << n << std::endl; }
        friend void test_2(void); 
        friend class X; 
}; 

class X 
{
    public: 
        static void test(void)
        {
            T t1(100, 200); 
            std::cout << "In static X::test()" << std::endl; 
            t1.show(); 
            t1.m = 500; 
            t1.n = 600;
            t1.show();  
        }

        void non_static_function()
        {   
            T t1(100, 200); 
            std::cout << "In static X::non_static_function()" << std::endl; 
            t1.show(); 
            t1.m = 500; 
            t1.n = 600;
            t1.show();  
        }
}; 

void test_1(void); 

int main(void)
{
    test_1(); 
    test_2(); 
    X::test(); 
    X objX; 
    objX.non_static_function(); 

    return 0; 
}

void test_1(void)
{
    T t1(100, 200); 
    std::cout << "In test_1()" << std::endl; 
    t1.show(); 
    // t1.m = 500; // CTE 
    //  t1.n = 600; // CTE 
}

void test_2(void)
{
    T t1(100, 200); 

    std::cout << "In test_2()" << std::endl; 
    t1.show(); 
    t1.m = 500; 
    t1.n = 600; 
    t1.show(); 
}