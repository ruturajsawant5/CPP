#include "complex.hpp"
#include <stdexcept>
#include <cstdio> 

complex::complex(double _re, double _im) : re(_re), im(_im)
{

}

complex complex::operator+(const complex& other)
{
    double re_summation, im_summation; 

    re_summation = this->re + other.re; 
    im_summation = this->im + other.im; 

    complex summation(re_summation, im_summation); 

    return (summation); 
}

complex complex::operator-(const complex& other)
{
    return complex(re - other.re, im - other.im); 
}

complex complex::operator*(const complex& other)
{
    return complex(re*other.re - im*other.im, re*other.im + im*other.re);  
}

complex complex::operator/(const complex& other)
{
    if(other.re == 0.0 && other.im == 0.0)
        throw std::runtime_error("Cannod divide by 0.0 + i * 0.0"); 
    return complex(
        (re*other.re + im*other.im)/(other.re*other.re + other.im*other.im), 
        (im*other.re - re*other.im)/(other.re*other.re + other.im*other.im)
    ); 
}

void complex::show(const char* msg) const
{
    if(msg)
        printf(msg); 
    printf("(%.3lf)+i(%.3lf)\n", re, im);    
}