#include <iostream> 
#include <stdexcept> 

double cpa_sqrt(double x); 

int main(void)
{
    double x; 
    double sqrt_x; 

    std::cout << "Enter a non-negative number to find the square root:"; 
    std::cin >> x; 
    try
    {
        sqrt_x = cpa_sqrt(x); 
        std::cout << "square root(" << x << ") = " << sqrt_x << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cout << "In catch block" << std::endl; 
        std::cout << "Survived" << std::endl; 
    }
    
    std::cout << "Moving forward" << std::endl; 
  
    return (EXIT_SUCCESS); 
}

double cpa_sqrt(double x)
{
    if(x < 0)
        throw std::domain_error("square root of negative number is not double"); 

    // compute square root of x 
    // and return 

    return 0.0; 
}
