#include <cstdio>

// CATEGORY I functions can access EVERY-THING IN CLASS 
// WRITTEN INSIDE ALL ACCESS SPECIFIERS 
// static/non-static data/function private/public/protected

class X{
    
    private: 
        int m; 
        void f(){
        }

    protected: 
        int n; 
        void g(){

        }

    public: 
        static int s_data; 
        static void s_func(int p, int q) {}
        int k; 
        void h(){
            // CAT-I
            // this->m, this->f(), this->n, this->g()
            // this->k, this->h(), this->s_func() 
            this->s_data; 
            X objX; 
            objX.s_data; 
            X* pX = new X; 
            pX->s_data; 
            // objX.m, objX.n, objX.k, objX.f(), objX.g(), 
            // objX.h() 

            // pX->m, pX->n, pX->k, pX->f(), pX->g(), pX->h() 
            delete pX; 
            pX = 0; 
        }
}; 

int X::s_data; 

// CATEGORY II function: A category II function can access 
// static/non-static data/function protected/public
class Y : public X 
{
    public: 
        void func(){
            this->n; 
            this->k; 
            this->g(); 
            this->h(); 
            this->s_func(100, 200);
            this->s_data;  

            X objX; 
            X* pX = new X; 

            // objx and pX are stand-alone objects of X 
            // not embedded in object Y, therefore, though
            // we are in class Y func, protected of objX and pX 
            // are NOT ACCESSIBLE here 

            objX.k; 
            objX.h(); 
            objX.s_data; 
            objX.s_func(100, 200); 

            pX->k; 
            pX->h(); 
            pX->s_data; 
            pX->s_func(100, 200); 

            delete pX; 
            pX = 0; 
        }
}; 

// CAT III : A function in CAT III can access only public members data/function

void test_func(){
    X objX; 
    X* pX = new X; 

    objX.k; 
    objX.h(); 
    objX.s_data; 
    objX.s_func(100, 200); 

    pX->k; 
    pX->h(); 
    pX->s_data; 
    pX->s_func(100, 200); 


    delete pX; 
    pX = 0; 
}

int main(void){
    test_func(); 
    Y objY; 
    objY.func(); 
    
    return (0); 
}