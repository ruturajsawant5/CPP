#include <iostream> 
#include <cmath> 
#include <stdexcept> 

class Quadrilateral
{
    private: 
        double s1, s2, s3, s4; 

    public: 
        Quadrilateral(double _s1, double _s2, double _s3, double _s4) : s1(_s1), 
                                                                        s2(_s2), 
                                                                        s3(_s3), 
                                                                        s4(_s4)
        {
            if( 
                s1 <= 0.0 || s2 <= 0.0 || s3 <= 0.0 || s4 <= 0.0 || 
                s1 + s2 + s3 <= s4 || s1 + s2 + s4 <= s3 || 
                s1 + s3 + s4 <= s2 || s2 + s3 + s4 <= s1
            )
                throw std::range_error("Invalid values for quadrilateral"); 

        }

        virtual double area() const
        {
            double s = (s1 + s2 + s3 + s4) / 2; 
            std::cout << "Inside Quadrilateral::area()" << std::endl; 
            return sqrt((s-s1) * (s-s2) * (s-s3) * (s-s4)); 
        }

        double perimeter() const
        {
            std::cout << "Inside Quadrilateral::perimeter()" << std::endl; 
            return (s1 + s2 + s3 + s4); 
        }
}; 

class Square : public Quadrilateral 
{
    private: 
        double s; 
    
    public: 
        Square(double _s) : Quadrilateral(_s, _s, _s, _s), s(_s)
        {

        }

        double area() const
        {
            std::cout << "Inside Square::area()" << std::endl; 
            return s*s; 
        }

        double get_diagonal_length() const 
        {
            return sqrt(2) * s; 
        }
}; 

int main(void)
{
    Quadrilateral* pQuad = new Quadrilateral(10.8, 14.1, 12.3, 17.5); 

    double A = pQuad->area(); 
    double P = pQuad->perimeter(); 

    std::cout << "Area = " << A << std::endl 
                << "Perimeter = " << P << std::endl; 

    delete pQuad; 
    pQuad = 0; 

    Square* pSquare = new Square(10); 
    A = pSquare->area(); 
    P = pSquare->perimeter(); 

    std::cout << "Area = " << A << std::endl 
            << "Perimeter = " << P << std::endl; 

    delete pSquare; 
    pSquare = 0; 

    pQuad = new Square(20); 
    
    A = pQuad->area(); 
    P = pQuad->perimeter(); 

    std::cout << " pQuad->Quadrilateral::area()" << std::endl; 
    pQuad->Quadrilateral::area(); 

    std::cout << "Area = " << A << std::endl 
                << "Perimeter = " << P << std::endl; 

    delete pQuad; 
    pQuad = 0; 

    return (0); 
}
