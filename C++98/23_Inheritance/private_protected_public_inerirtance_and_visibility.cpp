#include <cstdio> 

class Base 
{
    private: 
        int bn1_private, bn2_private; 
    protected: 
        int bn1_protected, bn2_protected; 
    public: 
        int bn1_pub, bn2_pub; 
}; 

class D1 : public Base 
{
    public: 
        void test()
        {
            puts("D1::test()"); 
            this->bn1_protected = 10; 
            this->bn2_protected = 20; 
            this->bn1_pub = 30; 
            this->bn2_pub = 40; 
        }
}; 

class D2 : protected Base 
{
    public: 
        void test()
        {
            puts("D2::test()"); 
            this->bn1_protected = 10; 
            this->bn2_protected = 20; 
            this->bn1_pub = 30; 
            this->bn2_pub = 40; 
        }
}; 

class D3 : private Base 
{
    public: 
        void test()
        {
            puts("D3::test()"); 
            this->bn1_protected = 10; 
            this->bn2_protected = 20; 
            this->bn1_pub = 30; 
            this->bn2_pub = 40; 
        }
}; 

class D11 : public D1 
{
    public: 
        void test()
        {
            puts("D11::test()"); 
            this->bn1_protected = 10; 
            this->bn2_protected = 20; 
            this->bn1_pub = 30; 
            this->bn2_pub = 40; 
        }
}; 

class D22 : public D2 
{
    public: 
        void test()
        {
            puts("D22::test()"); 
            this->bn1_protected = 10; 
            this->bn2_protected = 20; 
            this->bn1_pub = 30; 
            this->bn2_pub = 40; 
        }
};  

class D33 : public D3
{
    public: 
        void test()
        {
            puts("D33::test()");
            // No member of class Base instance 
            // in D33 object is accessible here. 
            //this->bn1_pub = 100;  //CTE
            //this->bn2_pub = 200;  //CTE
        }
}; 

void func(void) 
{
    D1 d1; 
    D2 d2; 
    D3 d3; 

    d1.bn1_pub = 100; 
    d1.bn2_pub = 200; 

    // No member of Base is accessible 
    // from d2 and d3. 
    //d2.bn1_pub = 1000; //CTE
    //d2.bn2_pub = 2000; //CTE
    //d3.bn1_pub = 10000; //CTE
    //d3.bn2_pub = 20000; //CTE
}

int main(void)
{
    func(); 
    return (0); 
}