/* 
    Let B be a polymorphic base class. 
    Let D1, D2 and D3 be sub-classes of B. 
    Class D1 has D1 specific member function h1(). 
    Class D2 has D2 specific member function h2().
    Class D3 has D3 specific member function h3().

    Let pB be a pointer of B and it is given that 
    it contains an address of one of its subclasses 
    D1, D2 or D3 which one, we don't know. 

    Write a code which will detect the subclass of 
    object hosted by pB and invoke subclass specific 
    member function on pB. 
*/

#include <iostream> 
#include <typeinfo> 

#include <cstdlib> 
#include <ctime> 

class B{
    public: 
        virtual void f(){
            std::cout << "B:f()" << std::endl; 
        }
}; 

class D1: public B{
    public: 
        void h1(){
            std::cout << "D1::h1()" << std::endl; 
        }
}; 

class D2: public B{
    public: 
        void h2(){
            std::cout << "D2::h2()" << std::endl; 
        }
}; 

class D3: public B{
    public: 
        void h3(){
            std::cout << "D3::h3()" << std::endl; 
        }
}; 

int main(){
    B* pB = 0; 

    srand(time(0)); 
    switch(rand() % 3)
    {
        case 0: 
            pB = new D1; 
            std::cout << "D1 selected" << std::endl; 
            break; 
        case 1: 
            pB = new D2; 
            std::cout << "D2 selected" << std::endl; 
            break; 
        case 2: 
            pB = new D3; 
            std::cout << "D3 selected" << std::endl; 
            break; 
    }
    
    if(typeid(*pB) == typeid(D1))
        dynamic_cast<D1*>(pB)->h1(); 
    else if(typeid(*pB) == typeid(D2))
        dynamic_cast<D2*>(pB)->h2(); 
    else if(typeid(*pB) == typeid(D3))
        dynamic_cast<D3*>(pB)->h3(); 

    delete pB; 
    pB = 0; 

    return 0; 
}