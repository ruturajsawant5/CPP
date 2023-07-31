#include <iostream> 
#include <stdexcept> 
#include <cmath> 

double f1(double x); 
double f2(double x); 
double cpa_sqrt(double x); 

int main(void)
{
    double x; 
    double sqrt_x; 

    std::cout << "Enter a non-negative number to find the square root:"; 
    std::cin >> x; 

    sqrt_x = f1(x); 
    std::cout << "sqrt(x):" << sqrt_x << std::endl; 
    
    // std::cout << "Moving forward" << std::endl; 
  
    return (EXIT_SUCCESS); 
}

double f1(double x)
{
    int m, n, k; 
    double rs; 
    
    m = 10; 
    n = 20; 

    rs = f2(x); 

    k = m + n; 
    k = m * n; 

    return (rs); 
}

double f2(double x)
{
    char c1, c2, c3; 
    double rs; 

    c1 = 'a'; 
    c2 = 'b'; 
    try 
    {
        rs = cpa_sqrt(x); 
    } 
    catch(const std::exception& ref)
    {
        std::cout << "First line of defense successful" << std::endl; 
        std::cout << ref.what() << std::endl; 
        return (NAN); 
    }

    c3 = c1 + c2; 
    return (rs); 
}

double cpa_sqrt(double x)
{
    if(x < 0)
        throw std::domain_error("square root of negative number is not double"); 

    // compute square root of x 
    // and return 

    return 0.0; 
}

// exception -> irrecoverable error condition 
// class 
// every exception is a class! 
// stdexcept -> namepace std -> exception 
// std::exception -> ROOT EXCEPTION CLASS 
// ANY DIRECT OR INDIRECT DERIVED CLASS OF ROOT EXCEPTION CLASS 
// IS KNOWN AS AN EXCEPTION 