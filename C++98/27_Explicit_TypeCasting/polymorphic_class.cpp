#include <cstdio> 
#include <cstdlib> 

class B 
{
    public: 
        void f() { puts("In B::f()"); }
        void g() { puts("In B::g()"); }
        virtual void ugach() { }
}; 

class D: public B
{
    public: 
        void g() { puts("In D::g()"); }
        void h() { puts("In D::h()"); }
}; 

int main(void)
{
    D objD; 
    B* pB = &objD; 

    pB->f(); // B::f() 
    pB->g(); // B::g()

    dynamic_cast<D*>(pB)->g(); 
    dynamic_cast<D*>(pB)->h(); 

    //reinterpret_cast<D*>(pB)->g(); 
    //reinterpret_cast<D*>(pB)->h();

    return 0; 
}