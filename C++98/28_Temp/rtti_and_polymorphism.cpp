#include <iostream> 
#include <typeinfo> 

class B 
{
    public: 
        virtual void f(){} 
        virtual void g(){}
}; 

class D1: public B 
{
    public: 
        void g() {} 
        void h() {} 
};

class D2: public B
{
    public: 
        void f() {}
        void k() {}
}; 

int main(void)
{
    B* pB1 = new D1; 
    B* pB2 = new D2; 

    std::cout << "type(pB1)=" <<  typeid(pB1).name() << std::endl; 
    std::cout << "type(pB2)=" <<  typeid(pB2).name() << std::endl; 
    std::cout << "type(*pB1)=" << typeid(*pB1).name() << std::endl; 
    std::cout << "type(*pB2)=" << typeid(*pB2).name() << std::endl; 

    return 0; 
}