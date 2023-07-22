#include <iostream> 

class Quadrilateral
{
    public: 
        double area() const
        {
            std::cout << "HORN'S FORMULA" << std::endl; 
            return 0.0; 
        }
}; 

class Rectangle : public Quadrilateral
{

public: 
    virtual double area() const 
    {
        std::cout << "use length * breadth formula" << std::endl; 
        return 0.0; 
    }
}; 

class Square : public Rectangle
{

    public: 

        double area() const 
        {
            std::cout << "Use side^2" << std::endl; 
            return 0.0; 
        }
}; 

int main(void)
{
    Quadrilateral* pQuad = new Rectangle; 
    Rectangle* pRectangle = new Square; 

    pQuad->area(); 
    pRectangle->area(); 

    delete pQuad; 
    pQuad=0; 

    delete pRectangle; 
    pRectangle=0; 

    return 0; 
}