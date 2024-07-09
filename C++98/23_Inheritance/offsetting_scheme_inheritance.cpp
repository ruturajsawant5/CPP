#include <cstdio> 

class B1 
{
    int m, n;

    public: 
        void f(){
            printf("B1::f():this=%llu\n", (unsigned long long)this); 
        }
}; 

class B2
{
    float f1, f2; 

    public: 
        void g(){
            printf("B2::g():this=%llu\n", (unsigned long long)this); 
        }
}; 

class D : public B1, public B2{ 
    double d1, d2; 

    public: 
        void h(){
            printf("D::h():this=%llu\n", (unsigned long long)this); 
        }
}; 

int main(void){
    D objD; 

    objD.f(); 
    objD.g(); 
    objD.h(); 

    return 0; 
}