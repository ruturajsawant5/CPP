#include <iostream> 

int num = 100; 

void f(void)
{
    std::cout << "Global::In f()" << std::endl; 
}

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int dd, int mm, int yy)
        {
            day = dd; 
            month = mm; 
            year = yy; 
        }

        void show() 
        {
            std::cout << "Global:" <<day << "-" << month << "-" << year << std::endl; 
        }
}; 

namespace X 
{
    int num = 100; 

    void f(void)
    {
        std::cout << "X:In f()" << std::endl; 
    }

    class Date 
    {
        private: 
            int day, month, year; 

        public: 
            Date(int dd, int mm, int yy)
            {
                day = dd; 
                month = mm; 
                year = yy; 
            }

            void show(); 
    }; 
}

void X::Date::show ()
{
    std::cout << "X:" << day << "-" << month << "-" << year << std::endl; 
}

namespace Y 
{
    int num = 1000; 

    void f(void)
    {
        std::cout << "Y:In f()" << std::endl; 
    }

    class Date 
    {
        private: 
            int day, month, year; 

        public: 
            Date(int dd, int mm, int yy)
            {
                day = dd; 
                month = mm; 
                year = yy; 
            }

            void show() 
            {
                std::cout << "Y:" << day << "-" << month << "-" << year << std::endl; 
            }
    }; 
}

int main(void)
{
    // accessing global versions of num, f() and class Date 

    std::cout << "global num:" << num << std::endl; 
    std::cout << "global num:" << ::num << std::endl; 

    f(); 
    ::f(); 

    Date d1(1, 1, 1970); 
    ::Date d2(2, 2, 1971); 

    d1.show(); 
    d2.show(); 

    // accessing versions num, f() and class Date belonging to namespace X 
    std::cout << "X::num ->" << X::num << std::endl; 
    X::f(); 
    X::Date d3(3, 3, 1972); 
    d3.show(); 

    // accessing versions of num, f() and class Date belonging to namespace Y 
    std::cout << "Y::num ->" << Y::num << std::endl; 
    Y::f(); 
    Y::Date d4(4, 4, 1973); 
    d4.show(); 

    return 0; 
}