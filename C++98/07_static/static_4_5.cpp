class Test 
{
    private: 
        static int num; 
        static int f(int, int); 
    public: 
        static int x; 
}; 

int Test::num; // memory will be allocated 
int Test::x; 

void xyz()
{
    Test::x; // ok 
    Test::num; // error 
}

class Date
{
    private: 
        int dd, mm, yy; 
    public: 
        Date(int _dd, int _mm, int _yy)
        {
            dd = _dd; 
            mm = _mm; 
            yy = _yy; 
        }
}; 

Date d(1, 1, 1970); 

.section .data 
    d: 
    .int    1 
    .int    1 
    .int    1970 

.section .bss 
    .comm   d, 12, 4

GLOBAL INITIALIZER BLOCK


