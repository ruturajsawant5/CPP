#ifndef COMPLEX_H 
#define COMPLEX_H 

class complex 
{
    private: 
        double re, im; 

    public: 
        complex(double _re = 0.0, double _im = 0.0); 
        complex operator+(const complex& other); 
        complex operator-(const complex& other); 
        complex operator*(const complex& other); 
        complex operator/(const complex& other); 
        void show(const char* msg) const; 
}; 


#endif // COMPLEX_H 