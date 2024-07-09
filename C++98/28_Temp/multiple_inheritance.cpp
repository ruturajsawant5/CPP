#include <cstdio> 
#include <cstdlib> 

class B1{
    private: 
        int m1, n1; 
    public: 
        void f(){
            puts("B1::f()"); 
        }

        void h1(){
            puts("B1::h1()"); 
        }
}; 

class B2{
    private: 
        int m2, n2; 
    public: 
        void f(){
            puts("B2::f()"); 
        }

        void h2(){
            puts("B2::h2()"); 
        }
}; 

class B3{
    private: 
        int m3, n4; 
    public: 
        void f(){
            puts("B3::f()"); 
        }

        void h3(){
            puts("B3::h3()"); 
        }
}; 

class D : public B1, public B2, public B3{
    private: 
        int md, nd; 

    public: 
        void k(){
            puts("D::k()"); 
        }
}; 

int main(){
    D objD; 

    //objD.f(); // D::f() is ambiguous -> CTE 
    objD.B1::f(); 
    objD.B2::f(); 
    objD.B3::f(); 
    objD.h1(); 
    objD.h2(); 
    objD.h3(); 
    objD.k(); 

    dynamic_cast<B1*>(&objD)->f(); 
    dynamic_cast<B2*>(&objD)->f(); 
    dynamic_cast<B3*>(&objD)->f(); 

    B1* pB1 = &objD;
    pB1->f(); 
    pB1->h1(); 
    reinterpret_cast<D*>(pB1)->k(); 
    
    reinterpret_cast<B2*>(pB1)->f(); 
    reinterpret_cast<B2*>(pB1)->h2(); 

    reinterpret_cast<B3*>(pB1)->f(); 
    reinterpret_cast<B3*>(pB1)->h3(); 

    return 0; 
}