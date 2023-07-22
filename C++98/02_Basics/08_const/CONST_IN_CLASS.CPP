#include <iostream> 

class Test 
{
    private: 
        int m; 
        const int k; 

    public: 
        Test(int _m, int _k) : m(_m), k(_k) {} 
        int get_m() const 
        {
            return m; 
        }

        /* 
            int get_m(const Test* this); 
        */
}; 

Test gt1(10, 20); // data section, r/w
const Test gt2(30, 40); // rodata section, ronly for lang, os, hw

int main(void)
{
    Test t1(100, 200);  // stack, r/w
    const Test t2(200, 300); // stack, ronly for lang, not for os and hw 
    static const Test t3(400, 500);  // data, ronly for lang, os, hw 

    gt1.get_m(); 
    gt2.get_m(); 
    t1.get_m(); 
    t2.get_m(); 
    t3.get_m(); 

    Test* pt1 = new Test(1000, 2000); 
    pt1->get_m(); 

    const Test* pt2 = new Test(3000, 4000); 
    pt2->get_m(); 

    static const Test* pt3 = new Test(5000, 6000); 
    pt3->get_m(); 
    
    Test* const pt4 = new Test(7000, 8000); 
    pt4->get_m(); 
    
    static Test* const pt5 = new Test(9000, 10000); 
    pt5->get_m(); 
    
    const Test* const pt6 = new Test(11000, 12000); 
    pt6->get_m(); 
    
    static const Test* const pt7 = new Test(13000, 14000); 
    pt7->get_m(); 

    delete pt1; 
    pt1 = 0; 

    delete pt2; 
    pt2 = 0; 

    delete pt3; 
    pt3 = 0; 

    delete pt4; 
    delete pt5; 
    delete pt6; 
    delete pt7; 
   
    return 0; 
}