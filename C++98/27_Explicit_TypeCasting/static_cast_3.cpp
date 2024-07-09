#include <iostream> 
#include <cstdlib> 

class I1{
    public: 
        virtual void f1() = 0; 
        virtual void f2() = 0;
        virtual void f3() = 0;
}; 

class I2{
    public: 
        virtual void g1() = 0; 
        virtual void g2() = 0;
}; 

class I3{
    public: 
        virtual void h1() = 0; 
        virtual void h2() = 0;
        virtual void h3() = 0;
        virtual void h4() = 0; 
}; 

class D : public I1, public I2, public I3{
    private: 
        double d1, d2, d3, d4; 
    public: 
        void f1(){
            std::cout << "this=" << std::hex << this << std::endl; 
            std::cout << "In D::f1()" << std::endl; 
        }

        void f2(){
            std::cout << "In D::f2()" << std::endl; 
        }

        void f3(){
            std::cout << "In D::f3()" << std::endl; 
        }

        void g1(){
            std::cout << "In D::g1()" << std::endl; 
        }

        void g2(){
            std::cout << "In D::g2()" << std::endl; 
        }

        void h1(){
            std::cout << "In D::h1()" << std::endl; 
        }

        void h2(){
            std::cout << "In D::h2()" << std::endl; 
        }

        void h3(){
            std::cout << "In D::h3()" << std::endl; 
        }

        void h4(){
            std::cout << "In D::h4()" << std::endl; 
        }
}; 

void test(D* pD); 

int main(void)
{
    D* pD = new D; 
    test(pD); 
    delete pD; 
    pD = 0; 
    return 0; 
}

void test(D* pD)
{
    I1* pI1 = static_cast<I1*>(pD); 
    I2* pI2 = static_cast<I2*>(pD); 
    I3* pI3 = static_cast<I3*>(pD); 

    std::cout << "pI1:" << std::hex << pI1 << std::endl; 
    std::cout << "pI2:" << std::hex << pI2 << std::endl; 
    std::cout << "pI3:" << std::hex << pI3 << std::endl; 

    pI1->f1(); 
    pI1->f2(); 
    pI1->f3(); 

    pI2->g1(); 
    pI2->g2(); 

    pI3->h1(); 
    pI3->h2(); 
    pI3->h3(); 
    pI3->h4(); 
}