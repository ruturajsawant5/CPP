#pragma once 

class IComplex 
{
    public: 
        virtual void show() const = 0; 
        // IComplex class has no obligation to 
        // define the member function show() 
        // and an object of IComplex cannot be created 
}; 

IComplex* get_complex_number_instance(double re, double im); 
