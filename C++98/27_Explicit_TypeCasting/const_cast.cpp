#include <cstdio> 
#include <cstdlib> 

const int gn = 100; 
int gm = 200; 
const int* gp1 = &gn; 
const int* gp2 = &gm; 

const int *const gp3 = &gn; 
int* const gp4 = &gm; 

void test(void); 

int main(void)
{
    test(); 
    return (0); 
}

void test(void)
{
    const int n = 100; 
    int m = 200; 
    const int* p1 = &n; 
    const int* p2 = &m; 
    const int *const p3 = &n; 
    int* const p4 = &m; 

    *const_cast<int*>(p1) = 1000; // n <- 1000
    *const_cast<int*>(p2) = 2000; // m <- 2000 

    *const_cast<int*>(p3) = 3000; // n == 1000->3000 
    *p4 = 4000; // m == 2000->4000
}