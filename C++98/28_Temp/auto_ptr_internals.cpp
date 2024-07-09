/*
X* pX = new X; 

std::auto_ptr<X>pX(new X); 

pX -> an object of type auto_ptr<X>
*/ 

#include <iostream> 

class X
{
    public: 
        ~X()
        {
            std::cout << "Object of class X, addressed at " << std::hex 
                        << this << " is about to be destroyed" << std::endl; 
        }

        void test(){ std::cout << "In X::test()" << std::endl;}
}; 

template <typename T> 
class auto_ptr
{
    private: 
        T* pT; 

    public: 
        auto_ptr(T* _pT) : pT(_pT){}
        
        T* get() { return pT; }
        
        T* operator->()
        {
            return pT; 
        }

        ~auto_ptr(){
            delete pT; 
        }
}; 

void test(void); 

int main(void)
{
    test(); 
}

void test(void) 
{
    auto_ptr<X> objX(new X); 

    objX.get(); 
    objX->test(); 
} 