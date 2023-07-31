#include "complex.hpp"

int main(void)
{
    complex c1(1.1, 2.2); 
    complex c2(3.3, 4.4); 

    complex c3 = c1 + c2; 
    complex c4 = c1 - c2; 
    complex c5 = c1 * c2; 
    complex c6 = c1 / c2; 

    c1.show("c1:"); 
    c2.show("c2:");
    c3.show("c3 which is c1+c2:"); 
    c4.show("c4 which is c1-c2:");
    c5.show("c5 which is c1*c2:");
    c6.show("c6 which is c1/c2:");

    return (0); 
}
