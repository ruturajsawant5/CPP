#include <cstdio> 
#include <cstdlib> 

#define prn(fn_name) printf("In %s\n", fn_name)

class B 
{
    public: 
        void f1() { prn("B::f1()"); }
        void f2() { prn("B::f2()"); }
        virtual void f3() { prn("B::f3()"); }
        virtual void f4() { prn("B::f4()"); }
        void h() { prn("B::h()"); }
}; 

class D: public B 
{
    public: 
        void g1() { prn("D::g1()"); }
        void g2() { prn("D::g2()"); }
        void f3() { prn("D::f3()"); }
        void f4() { prn("D::f4()"); }
        void h() { prn("D::h()"); }
}; 

int main(void) 
{
    D objD; 
    B* pB = &objD; 
    D* pD = &objD; 

    puts("On pB"); 
    pB->f1();   // B::f1() 
    pB->f2();   // B::f2()
    pB->B::f3(); // B::f3() 
    pB->B::f4(); // B::f4() 
    pB->f3();   // D::f3()
    pB->f4();   // D::f4() 
    dynamic_cast<D*>(pB)->g1(); // D::g1() 
    dynamic_cast<D*>(pB)->g2(); // D::g2() 
    pB->h(); // B::h()
    dynamic_cast<D*>(pB)->h(); // D::h()

    puts("On pD"); 
    pD->f1();   // B::f1() 
    pD->f2();   // B::f2() 
    pD->B::f3(); // B::f3() 
    pD->B::f4(); // B::f4() 
    pD->f3(); // D::f3() 
    pD->f4(); // D::f4() 
    pD->g1(); // D::g1() 
    pD->g2(); // D::g2() 
    pD->B::h(); // B::h()
    pD->h(); // D::h() 
  
    return (0); 
}