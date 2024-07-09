#include <iostream> 
#include <cstdlib> 

#include "IComplex.hpp"

int main(void)
{
    IComplex* pC1 = get_complex_number_instance(1.1, 2.2); 
    IComplex* pC2 = get_complex_number_instance(3.3, 4.4); 

    pC1->show(); 
    pC2->show(); 

    delete pC1; 
    delete pC2; 

    return 0; 
}

// Tree (BST)
// Vector 
// List 