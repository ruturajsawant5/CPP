#include <iostream> 
#include <cstdio> 
#include <cstdlib> 

class X 
{
    public: 
        virtual void test_func() {} 
}; 

class Y : public X 
{
    public: 
        void test_func() 
        {
            std::cout << "In Y::test_func()" << std::endl; 
        }
}; 

X* get_X_instance()
{
    return new Y; 
}

class X1 
{
    public: 
        virtual void test_func() = 0; 
}; 

int main(void)
{
    X objX; 

    objX.test_func(); 

    X* pX = new Y; 
    pX->test_func(); 

    delete pX; 
    pX = NULL; 

    X1 objX1; // X1 object cannot be created 
    X1* pX1 = new X1; // X1 object cannot be created

    return 0; 
}

/* 
    A class whose all members are pure and virtual is known as 
    the pure abstance base class 
*/

/* 
global function cannot be made pure 

void test_func() = 0; // error 

namespace X 
{
    void test_func() = 0; // error 
}

class Z 
{
    static void test_func() = 0; // error
}; 

class C 
{
    public: 
        virtual void test_fun(int, int) = 0; 
        void test() = 0; // error. non static member function must be virtual 
}; 

If one applies pure specifier to non-static virtual function in class 
then there is NO OBLIGATION TO IMPLEMENT IT. 

Object of that class cannot be created. Instantiation of such class containing 
non-static virtual function with pure specifier is disabled at compile level. 

Pure specifier : Eligibility: 
    non-static virtual member function of clas s

Effect: 
    No obligation to define it and class cannot be instantiated. 

*/