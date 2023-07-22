#include <iostream> 

class Date_1 
{
    private: 
        int dd, mm, yy; 
    public: 
    // default construtor 
        Date_1() 
        {
            dd = 1; 
            mm = 1; 
            yy = 1970; 
        } 
    // parameterized constructor 
        Date_1(int _dd, int _mm, int _yy)
        {
            dd = _dd; 
            mm = _mm; 
            yy = _yy; 
        }
    // parameterized constructor 
        Date_1(char* date)
        {

        }
}; 

class Date_2
{
    private: 
        int dd, mm, yy; 

    public: 
        Date_2(int _dd=1, int _mm=1, int _yy=1970)
        {
            dd = _dd; 
            mm = _mm; 
            yy = _yy; 
        }
}; 

int main(void)
{
    Date_1 d1; 
    Date_1 d2(10, 3, 2012); 
    Date_1 d3("31/9/2025"); 

    Date_2 d22; 
    Date_2 d23(1, 2, 1996); 

    return (0); 
}