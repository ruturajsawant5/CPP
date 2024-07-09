#include <iostream> 
class X
{
    public: 
        ~X()
        {
            std::cout << "Object of class X, addressed at " << std::hex 
                        << this << " is about to be destroyed" << std::endl; 
        }
}; 

void test1(void); 
void test2(void); 

int main(void)
{
    test1(); 
    test2(); 
    while(1){

    }

    return (0); 
}

void test1(void)
{   
    X objX;    
    std::cout << "&objX:" << &objX << std::endl;  
}

void test2(void)
{
    X* pX = new X; 
    std::cout << "pX:" << pX << std::endl; 
    // Memory leak 
}