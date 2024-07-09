#include <cstdio> 
#include <cstdlib> 

class B {
    public: 
        B(){
            puts("Constructor B"); 
        }

        void h(){
            puts("B::h()"); 
        }

        virtual void k(){
            puts("B::k()"); 
        }

        virtual void proc(){
            puts("B::proc()"); 
        }
};

class B1 : public B{
    public: 
        B1(){
            puts("Constructor B1"); 
        }

        void proc(){
            puts("In B1::proc()"); 
        }
}; 

class B2 : public B{
    public: 
        B2(){
            puts("Constructor B2"); 
        }
}; 

class D : public B1, public B2{
    public: 
        D(){
            puts("Constructor D"); 
        }
}; 

int main(void){
    D objD; 
    // objD.h();   // Ambiguous call to B::h()
    // objD.k();   // Ambiguous call to B::k()
    objD.B::h(); 
    objD.B::k(); 
    objD.B::proc(); 
    objD.B1::proc(); 
    return 0; 
}