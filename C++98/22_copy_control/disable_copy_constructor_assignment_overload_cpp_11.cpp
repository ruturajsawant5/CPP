/* Solution 1: 
    HasPtr hp1(100, 200); 
    HasPtr hp2(hp1); 
    HasPtr hp3(400, 500); 
    hp1 = hp3; 

    SHOULD BE ERROR. 
    Under C++ 11: We can ensure a compiletime error
*/

#include <iostream> 
#include <stdexcept>

class HasPtr
{
    private: 
        int n; 
        int* ptr; 

    public: 
        HasPtr(int _n, int _m) : n(_n), ptr(new int(_m)) 
        {

        }

        int get_ptr_data() const 
        {
            return *ptr; 
        }

        void set_ptr_data(int new_data)
        {
            *ptr = new_data; 
        }

        void invalidate_ptr() 
        {
            delete ptr; 
        }

        ~HasPtr()
        {
            delete ptr; 
        }

        HasPtr::HasPtr(const HasPtr& other) = delete; 
        HasPtr& HasPtr::operator=(const HasPtr& other) = delete; 
       
}; 

int main(void)
{
    HasPtr hp1(100, 200); 

    try 
    {
       HasPtr hp2(hp1); 
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl; 
    }

    HasPtr hp3(400, 500); 

    try 
    {
        hp1 = hp3; 
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl; 
    }

    return (0); 
}