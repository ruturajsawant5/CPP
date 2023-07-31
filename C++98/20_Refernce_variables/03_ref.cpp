#include <iostream> 
#include <cstdlib> 

void swap(int& n1, int& n2); 
int& get_int(int init_n); 

int main(void)
{
    int n = 10; 
    int& ref = n; // ref is an alias to n 

    std::cout << "n:" << n << std::endl; 
    ref = 20; 
    std::cout << "n:" << n << std::endl; 

    int p = 100, q=200; 

    std::cout << "BEFORE:p:" << p << " q:" << q << std::endl; 
    swap(p, q); 
    std::cout << "After:p:" << p << " q:" << q << std::endl; 

    int* p_int = new int(100); 
    int& ref_int = *p_int; 

    //int& ref1 = 10; // error: rhs is of type int but not valid lvalue 
    //int& ref2 = n + 5; // error: rhs is of type int byt not valid lvalue 
    //int& ref3 = n;  // ok: n is of type int and n is valid lvalue 
    //int& ref4 = *p_int; // ok; *p_int is of the type int and is a valid lvalue 
    
    // Generalised 
    // T& ref = rhs 
    // rhs must be an lvalue of type T 

    int& r = get_int(500); 

    std::cout << "ref_int:" << ref_int << std::endl 
                << "r:" << r << std::endl; 

    delete &ref_int; 
    delete &r; 

    return (0); 
}

void swap(int& n1, int& n2)
{
    int tmp; 

    tmp = n1; 
    n1 = n2; 
    n2 = tmp; 
}

int& get_int(int init_n)
{
    return *new int(init_n); 
}

// T& ref = rhs; 
// rhs must be a valid lvalue expr of type T 

// C++ 98 -> ref -> reference variable 
// C++11 -> ref -> lvalue reference variable 

// T&& r_ref = rhs; 
// any expression of type T which is NOT 
// a valid lvalue but a valid rvalue

// int&& rr1 = 10;      // ok 
// int&& rr2 = n + 5;   // ok 