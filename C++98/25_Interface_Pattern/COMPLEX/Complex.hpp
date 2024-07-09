#include <iostream> 
#include <cstdio> 
#include "IComplex.hpp"

class CPA_Complex : public IComplex 
{
    private: 
        double re, im; 

    public: 
        CPA_Complex(double _re, double _im); 
        void show() const; 
}; 

