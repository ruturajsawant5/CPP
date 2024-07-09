#include <cstdio> 
#include <cstdlib> 


// PART 1 : Unqualified access and global qualified access 
void test_func(void); 
int n = 1; 
void test_func(void)
{
    int n=10; 
    int m1=20;

    ::n; // qualified access to global n 
    try 
    {
        int n=100; 
        int m2 = 200; 

        for(int i = 0; i < 5; ++i)
        {
            int n = 1000; 
            int m3 = 2000; 
            for(int j = 0; j < 5; ++j)
            {
                int n = 10000; 
                int m4 = 20000;
                if(i > j)
                {
                    int n = 100000; 
                    int m5 = 200000; 
                    // Unqualified access to innermost n (with value  100000)
                    // and m5, j, m4, i, m3, m2, m1 
                    ::n; // qualified access to global n 
                } 

                // Unqualified access to innermost n (with value 10000)
                // and  j, m4, i, m3, m2, m1 
                ::n; // qualified access to global n 
            }
            // Unqualified access to innermost n (with value 1000)
            // and i, m3, m2, m1 
            ::n; // qualified access to global n 
        }

        // Unqualified access to innermost n (with value 100)
        // and  m2, m1 
        ::n; // qualified access to global n 
    } 
    catch(...)
    {

    }

    // Unqualified access to innermost n (with value 100)
    //  m1 
}

// PART 2: Qualified access using class variable name: statics inside class 

void access_1(void); 
void access_2(void); 
class X1 
{
    friend void access_2(void); 
    private: 
        static int n1; 
        static void sf1() {} 
    protected: 
        static int n3; 
        static void sf2() {} 
    public: 
        static int n2; 
        static void sf3() {} 
}; 

int X1::n1; 
int X1::n2; 
int X1::n3; 

void access_1(void)
{
    X1::n2=100; // qualified access to static variable 
    // X1::n1 // access speifier filter 
    X1::sf3(); 

}

void access_2(void)
{
    X1::n1; // private 
    X1::n2; // public 
    X1::n3; // protected 
    X1::sf1(); 
    X1::sf2(); 
    X1::sf3(); 
}

// PART 2: Qualified access using namespace and scope resolution operator 

namespace X2 
{
    class C2 
    {
        public: 
            static int C2_n; 
    }; 

    void func(void)
    {

    }

    float fnum; 
}; 

int X2::C2::C2_n; 

void access_3(void) 
{
    X2::C2 objC2; 
    objC2.C2_n; 

    X2::func(); 
    X2::fnum; 
}