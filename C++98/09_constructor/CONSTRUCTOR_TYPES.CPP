#include <iostream> 

class X 
{
    private: 
        int m, n; 
    public: 
    
    // SYNTHESIZED DEFAULT CONSTRUCTOR         
}; 

class Y 
{
    private: 
        int m, n; 

    public: 
        // DEFAULT CONSTRUCTOR  
        Y()
        {
            // KHOOP LINES ASU SHAKTAT
            m = 0; 
            n = 0; 
        }
}; 

class Z 
{
    private: 
        int m, n; 
    public: 
        // PARAMETERIZED CONSTRUCTOR 
        Z(int _m, int _n) 
        {
            m = _m; 
            n = _n; 
        }
}; 

void test_X(void); 
void test_Y(void); 
void test_Z(void); 

int main(void)
{
    test_X(); 
    test_Y(); 
    test_Z(); 
    return 0; 
}

void test_X(void)
{
    X objX;         // stack, 8 bytes 
    X* pX = new X;  // free store(heap on VM)
    // X objX(); 
    // X* pX = new X(); 
    
    /* 
        Since, class definition writer has not defined 
        a constructor, it will be synthesized by the compliler

        Such constructor does not have any other parameter apart 
        from invisible this pointer. 

        Such constructor does not have any body. 

        Name: Synthesized Constructor 
    */

   delete pX; 
   pX = 0; 
}

/*

Dispelling the myth that the default 
constructor's body must be empty 

class QMainWindow {}; 

class CPA_Main_Window : public QMainWindow 
{
    CPA_Main_Window() : QMainWindow() 
    {
        // 500-600 lines of code 
        // adding widgets to window 
        // and connecting their signals with slots 
    }
}; 

*/

void test_Y(void)
{
    Y objY; 
    Y* pY = new Y; 

    delete pY; 
    pY=0; 
}

void test_Z(void)
{
    Z objZ1(100, 200); 
    
    int x=1000, y=2000; 

    Z objZ2(x, y); 
    Z objZ3(x, 200); 

    Z* objZ4 = new Z(4000, y); 

    delete objZ4; 
    objZ4 = 0; 
}