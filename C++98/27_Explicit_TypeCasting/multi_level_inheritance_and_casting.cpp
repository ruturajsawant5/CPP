#include <cstdio> 
#include <cstdlib> 

#define prn(fn_name) printf("In %s\n", fn_name)

class B1
{
    public: 
        void f1() { prn("In B1::f1()"); }
        virtual void g() { prn("In B1::g()"); }
        void h() { prn("In B1::h()"); }
}; 

class B2: public B1
{
     public: 
        void f2() { prn("In B2::f2()"); }
        void g() { prn("In B2::g()"); }
        void h() { prn("In B2::h()"); }
}; 

class B3: public B2
{
     public: 
        void f3() { prn("In B3::f3()"); }
        void g() { prn("In B3::g()"); }
        void h() { prn("In B3::h()"); }
}; 

class D: public B3
{
     public: 
        void fD() { prn("In D::fD()"); }
        void g() { prn("In D::g()"); }
        void h() { prn("In D::h()"); }
}; 

int main(void)
{
    D objD; 
    D* pD = &objD; 
    B3* pB3 = &objD; 
    B2* pB2 = &objD; 
    B1* pB1 = &objD; 

    puts("On pD"); 

    pD->f1();       // B1::f1() 
    pD->B1::g();    // B1::g() 
    pD->B1::h();    // B1::h()

    pD->f2();       // B2::f2()
    pD->B2::g();    // B2::g() 
    pD->B2::h();    // B2::h() 

    pD->f3();       // B3::f3() 
    pD->B3::g();    // B3::g() 
    pD->B3::h();    // B3::h()

    pD->fD();       // D::fD()
    pD->g();        // D::g() 
    pD->h();        // D::h() 

    puts("On pB3"); 
    pB3->f1();  
    pB3->B1::g(); 
    pB3->B1::h(); 

    pB3->f2(); 
    pB3->B2::g(); 
    pB3->B2::h(); 

    pB3->f3(); 
    pB3->B3::g(); // here B3::g() to SUPPRESS effect of virtual 
    pB3->h();     // here, there is no virtual so no qualification required 

    dynamic_cast<D*>(pB3)->fD(); 
    dynamic_cast<D*>(pB3)->g(); 
    dynamic_cast<D*>(pB3)->h(); 

    puts("On pB2"); 

    pB2->f1(); 
    pB2->B1::g(); 
    pB2->B1::h(); 

    pB2->f2(); 
    pB2->B2::g(); 
    pB2->h(); 

    dynamic_cast<B3*>(pB2)->f3(); 
    dynamic_cast<B3*>(pB2)->B3::g(); 
    dynamic_cast<B3*>(pB2)->h(); 

    dynamic_cast<D*>(pB2)->fD(); 
    dynamic_cast<D*>(pB2)->g(); 
    dynamic_cast<D*>(pB2)->h(); 

    puts("On pB1"); 
    pB1->f1(); 
    pB1->B1::g(); 
    pB1->h(); 

    dynamic_cast<B2*>(pB1)->f2(); 
    dynamic_cast<B2*>(pB1)->B2::g(); 
    dynamic_cast<B2*>(pB1)->B2::h(); 

    dynamic_cast<B3*>(pB1)->f3(); 
    dynamic_cast<B3*>(pB1)->B3::g(); 
    dynamic_cast<B3*>(pB1)->B3::h(); 

    dynamic_cast<D*>(pB1)->fD(); 
    dynamic_cast<D*>(pB1)->g(); 
    dynamic_cast<D*>(pB1)->h(); 

    return 0; 
}
