#include <iostream> 

int gnum; 

class X
{
    public: 
        ~X()
        {
            std::cout << "Object of class X, addressed at " << std::hex 
                        << this << " is about to be destroyed" << std::endl; 
        }
}; 

void f1(void); 
void f2(void); 
void f3(void); 
void f4(void); 

int main(int argc, char* argv[]) 
{   
    int num; 
    if(argc != 2)
    {
        std::cout << "UsageError" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    num = atoi(argv[1]); 
    if(num % 2 == 0)
        gnum = 0; 
    else 
        gnum = 1; 

    try
    {
        f1(); 
    }
    catch(std::domain_error& e)
    {
        std::cout << e.what() << std::endl; 
    }

    std::cout << "Entering in event loop:" << std::endl; 
    while(1)
        ;

    return 0;  
}

void f1(void)
{
    f2(); 
}

void f2(void)
{
    X* pX = new X; 
    std::cout << "Addr(pX):" << std::hex << pX << std::endl; 
    std::cout << "Calling f3()" << std::endl; 
    f3(); 
    std::cout << "Returned from f3()" << std::endl; 
    delete pX; 
    pX = 0; 
}

void f3(void)
{
    f4(); 
}

void f4(void)
{
    if(gnum % 2 == 0)
        std::cout << "Acceptable even number:" << gnum << std::endl; 
    else 
        throw std::domain_error("Even number expected"); 
}