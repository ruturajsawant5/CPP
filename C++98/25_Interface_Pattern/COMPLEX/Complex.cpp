#include <cstdio> 
#include "IComplex.hpp"
#include "Complex.hpp" 


CPA_Complex::CPA_Complex(double _re, double _im) : re(_re), im(_im)
{

}

void CPA_Complex::show() const
{
    printf("(%.3f)+i(%.3f))\n", re, im); 
}

IComplex* get_complex_number_instance(double re, double im)
{
    return new CPA_Complex(re, im); 
}