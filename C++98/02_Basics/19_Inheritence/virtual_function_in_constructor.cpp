#include <iostream> 
#include <typeinfo> 

class Base 
{
    public: 
        Base() 
        {
            this->f(); 
            std::cout << "typeid(*this).name()=" << typeid(*this).name() << std::endl; 
        }

        virtual void f()
        {
            std::cout << "Base::f()" << std::endl; 
        }
}; 

class Derived : public Base
{
    public: 
        Derived() : Base() 
        {
            std::cout << "typeid(*this).name()=" << typeid(*this).name() << std::endl;
        }

        void f()
        {
            std::cout << "Derived::f()" << std::endl; 
        }
}; 

int main(void)
{
    Base* pB = new Base; 
    Derived* pD = new Derived; 

    delete pB; 
    pB = 0; 

    delete pD; 
    pD = 0; 

    return 0; 
}